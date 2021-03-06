#include "game.hpp"
#include "logger.hpp"
#include "currentGame.hpp"

#include <SFML/Graphics.hpp>

void Game::addRandomObstacle() {
	std::uniform_int_distribution<int> widthDistribution(0, width / 2);
	std::uniform_int_distribution<int> heightDistribution(0, height / 2);

	int obstacleX = widthDistribution(random) * 2;
	int obstacleY = heightDistribution(random) * 2;

	if (map[obstacleX][obstacleY].getType() == crs::AIR) {
		map[obstacleX][obstacleY].setType(crs::OBSTACLE);
	} else {
		addRandomObstacle();
	}
}

bool Game::isObstacle(int locX, int locY) {
	return map[locX][locY].getType() == crs::OBSTACLE;
}

crs::Location *Game::randomFruitLocation() {
	sf::Vector2<float> viewSize = window->getView().getSize();
	sf::Vector2<float> viewOrigin = sf::Vector2<float>(window->getView().getCenter().x - (viewSize.x / 2), window->getView().getCenter().y - (viewSize.y / 2));

	std::uniform_int_distribution<int> widthDistribution(viewOrigin.x, viewOrigin.x + viewSize.x - 1);
	std::uniform_int_distribution<int> heightDistribution(viewOrigin.y, viewOrigin.y + viewSize.y - 1);

	int newFruitX = widthDistribution(random) / blockSize;
	int newFruitY = heightDistribution(random) / blockSize;

	if (map[newFruitX][newFruitY].getType() != crs::AIR) {
		randomFruitLocation();
	}

	return new crs::Location(newFruitX, newFruitY);
}

bool Game::bfs() {
	/*
	 * SETUP
	 */

	bool visited[width][height];
	for (auto & i : visited) {
		for (bool & j : i)
			j = false;
	}

	moveCount = 0;
	int nodesLeftInLayer = 1;
	int nodesInNextLayer = 0;

	PathfinderTile* finishTile = nullptr;

	bool reachedFinish = false;

	std::list<PathfinderTile> queue;

	/*
	 * ALGORITHM
	 */

	crs::Location* playerLocation = clientPlayer->getLocation();

	visited[playerLocation->getX()][playerLocation->getY()] = true;
	map[playerLocation->getX()][playerLocation->getY()].setType(crs::VISITED);
	queue.emplace_back(playerLocation->getX(), playerLocation->getY());

	std::list<PathfinderTile>::iterator i;

	while (!queue.empty()) {
		PathfinderTile currentTile = queue.front();
		queue.pop_front();

		if (map[currentTile.getX()][currentTile.getY()].getType() == crs::FRUIT) {
			reachedFinish = true;
			finishTile = &currentTile;
			break;
		}

		std::list<PathfinderTile> adjacentBlocks = currentTile.getAdjacentTiles(this);
		for (i = adjacentBlocks.begin(); i != adjacentBlocks.end(); i++) {
			PathfinderTile adjacentTile = *i;
			if (visited[adjacentTile.getX()][adjacentTile.getY()]) continue;

			visited[adjacentTile.getX()][adjacentTile.getY()] = true;
			if (map[adjacentTile.getX()][adjacentTile.getY()].getType() != crs::FRUIT) {
				map[adjacentTile.getX()][adjacentTile.getY()].setType(crs::VISITED);
			}
			queue.push_back(adjacentTile);

			nodesInNextLayer++;
		}

		nodesLeftInLayer--;
		if (nodesLeftInLayer == 0) {
			nodesLeftInLayer = nodesInNextLayer;
			nodesInNextLayer = 0;
			moveCount++;
		}
	}

	for (auto & loopX : map) {
		for (auto & loopY : loopX) {
			if (loopY.getType() == crs::VISITED) {
				loopY.setType(crs::AIR);
			}
		}
	}

	PathfinderTile* current = finishTile;
	while (!current->isFirst()) {
		map[current->getX()][current->getY()].setType(crs::VISITED);
		current = current->getPrevious();
	}

	std::cout << current->getX() << " " << current->getY() << std::endl;

	draw(0);

	return reachedFinish;
}

Game::Game(sf::RenderWindow* window) { // NOLINT(cert-msc51-cpp)
	crs::currentGame = this;

	gameOver = false;
	direction = crs::STOP;
	moving = crs::STOP;
	score = 0;
	this->window = window;

	random.seed(time(nullptr) * 5);

	for (int loopX = 0; loopX < width; loopX++) {
		for (int loopY = 0; loopY < height; loopY++) {
			map[loopX][loopY].setX(loopX);
			map[loopX][loopY].setY(loopY);
		}
	}

	sf::View view = sf::View();
	view.setCenter((float) width / 2, (float) height / 2);
	view.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));
	view.zoom(zoom);
	window->setView(view);

	clientPlayer = new Player(new crs::Location(width / 2, height / 2), sf::Color::Cyan);
	players.push_back(clientPlayer);

	fruitLocation = randomFruitLocation();
	map[fruitLocation->getX()][fruitLocation->getY()].setType(crs::FRUIT);

	for (int i = 0; i < 30; i++) {
		addRandomObstacle();
	}

	sf::Font font;
	if (!font.loadFromFile("/System/Library/Fonts/Helvetica.ttc")) {
		std::cout << "Error: Could not load font!" << std::endl;
	}

	mainFont = font;
}

void Game::draw(float alpha) {
	window->clear(sf::Color::Black);

	for (auto & loopX : map) {
		for (auto & loopY : loopX) {
			loopY.draw(window);
		}
	}

	for (auto & player : players) {
		player->draw(window, alpha, moving);
	}

	sf::View view = sf::View();

	view.setCenter((float) width / 2, (float) height / 2);
	view.reset(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y));

	//Interpolate zoom
	float framesPassed;
	if (waitBeforeZoom != 0) {
		framesPassed = (float) (maxWaitBeforeZoom - waitBeforeZoom) + alpha;
	} else {
		framesPassed = (float) maxWaitBeforeZoom;
	}
	float newZoom = zoom + ((zoom - previousZoom) * framesPassed / (float) maxWaitBeforeZoom) - (zoom - previousZoom);
	view.zoom(newZoom);

	window->setView(view);

	window->display();
}

void Game::input() {
	direction = crs::STOP;

	sf::Event event{};
	while (window->pollEvent(event)) {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up) {
				direction = crs::UP;
			} else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left) {
				direction = crs::LEFT;
			} else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down) {
				direction = crs::DOWN;
			} else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right) {
				direction = crs::RIGHT;
			} else if (event.key.code == sf::Keyboard::M) {
				direction = crs::AUTO;
			} else if (event.key.code == sf::Keyboard::Q) {
				crs::Event* crsEvent = new crs::QuitEvent();
				auto* quitEvent = (crs::QuitEvent*) crsEvent;
				PluginManager::instance.broadcastEvent(crsEvent);

				gameOver = !quitEvent->isCancelled();
			} else if (event.key.code == sf::Keyboard::B) {
				std::cout << Logger::info << "Player: " << clientPlayer->getLocation()->getX() << " " << clientPlayer->getLocation()->getY() << std::endl;
				std::cout << Logger::info << "Fruit: " << fruitLocation->getX() << " " << fruitLocation->getY() << std::endl;
			} else if (event.key.code == sf::Keyboard::U) {
				setZoom(zoom + 0.1f);
			}
		} else if (event.type == sf::Event::Closed) {
			window->close();
		}
	}
}

void Game::logic() {
	if (waitBeforeZoom == 0) {
		previousZoom = zoom;
	} else {
		waitBeforeZoom--;
	}

	moving = crs::STOP;

	movePlayer(direction);

	if (clientPlayer->getLocation()->getX() == fruitLocation->getX() && clientPlayer->getLocation()->getY() == fruitLocation->getY()) {
		score++;
		setZoom(zoom + 0.1f);
		crs::Location* newFruitLoc = randomFruitLocation();

		crs::Event* event = new crs::CrossFoundEvent(crs::Location(fruitLocation->getX(), fruitLocation->getY()), newFruitLoc);
		PluginManager::instance.broadcastEvent(event);

		setFruitLocation(((crs::CrossFoundEvent*) event)->getNewCrossLocation());
	}
}

[[nodiscard]] bool Game::isGameOver() const {
	return gameOver;
}

[[nodiscard]] int Game::getScore() const {
	return score;
}

[[nodiscard]] sf::Font Game::getMainFont() const {
	return mainFont;
}

void Game::setZoom(float newZoom) {
	if (newZoom <= 1.1 && newZoom >= 0) {
		previousZoom = zoom;
		zoom = newZoom;
		waitBeforeZoom = maxWaitBeforeZoom;
	}
}

Game::~Game() {
	delete fruitLocation;
	delete clientPlayer;
}

void Game::setFruitLocation(crs::Location *location) {
	map[fruitLocation->getX()][fruitLocation->getY()].setType(crs::AIR);
	delete fruitLocation;
	fruitLocation = location;
	if (map[fruitLocation->getX()][fruitLocation->getY()].getType() != crs::AIR) {
		fruitLocation = randomFruitLocation();
		std::cerr << Logger::warning << "Cross placed on not-air tile by plugin. Location changed." << std::endl;
	}
	map[fruitLocation->getX()][fruitLocation->getY()].setType(crs::FRUIT);
}

bool Game::movePlayer(crs::Direction moveDirection) {
	if (direction == crs::STOP) return false;

	int fruitX = fruitLocation->getX();
	int fruitY = fruitLocation->getY();

	int x = clientPlayer->getLocation()->getX();
	int y = clientPlayer->getLocation()->getY();

	if (moveDirection == crs::AUTO) {
		bfs();

		if (x > fruitX) {
			if (fruitX - x < (0 - width)/2) {
				moveDirection = crs::RIGHT;
			} else {
				moveDirection = crs::LEFT;
			}
		} else if (x < fruitX) {
			if (fruitX - x > width/2) {
				moveDirection = crs::LEFT;
			} else {
				moveDirection = crs::RIGHT;
			}
		} else if (y > fruitY) {
			if (fruitY - y < (0 - height)/2) {
				moveDirection = crs::DOWN;
			} else {
				moveDirection = crs::UP;
			}
		} else if (y < fruitY) {
			if (fruitY - y > height/2) {
				moveDirection = crs::UP;
			} else {
				moveDirection = crs::DOWN;
			}
		}
	}

	auto* newLocation = new crs::Location(clientPlayer->getLocation()->getX(), clientPlayer->getLocation()->getY());

	switch (moveDirection) {
		case crs::UP:
			if (y > 0) {
				if (!isObstacle(x, y - 1)) {
					moving = crs::UP;
					newLocation = new crs::Location(x, y - 1);
				} else {
					moving = crs::STOP;
				}
			} else {
				moving = crs::UP;
				newLocation = new crs::Location(x, height - 1);
			}
			break;
		case crs::LEFT:
			if (x > 0) {
				if (!isObstacle(x - 1, y)) {
					moving = crs::LEFT;
					newLocation = new crs::Location(x - 1, y);
				} else {
					moving = crs::STOP;
				}
			} else {
				moving = crs::LEFT;
				newLocation = new crs::Location(width - 1, y);
			}
			break;
		case crs::DOWN:
			if (y < height - 1) {
				if (!isObstacle(x, y + 1)) {
					moving = crs::DOWN;
					newLocation = new crs::Location(x, y + 1);
				} else {
					moving = crs::STOP;
				}
			} else {
				moving = crs::DOWN;
				newLocation = new crs::Location(x, 0);
			}
			break;
		case crs::RIGHT:
			if (x < width - 1) {
				if (!isObstacle(x + 1, y)) {
					moving = crs::RIGHT;
					newLocation = new crs::Location(x + 1, y);
				} else {
					moving = crs::STOP;
				}
			} else {
				moving = crs::RIGHT;
				newLocation = new crs::Location(0, y);
			}
			break;
		default:
			break;
	}

	crs::Event* event = new crs::MoveEvent(moveDirection, newLocation);
	auto* moveEvent = (crs::MoveEvent*) event;
	PluginManager::instance.broadcastEvent(event);

	if (moveEvent->isCancelled()) return false;

	clientPlayer->setLocation(moveEvent->getNewLocation());

	return true;
}

void Game::setTileType(const crs::Location& location, crs::TileType type) {
	map[location.getX()][location.getY()].setType(type);
}

crs::TileType Game::getTileType(const crs::Location& location) {
	return map[location.getX()][location.getY()].getType();
}
