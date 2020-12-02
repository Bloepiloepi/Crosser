#include "game.hpp"
#include <iostream>

void Tile::draw(sf::RenderWindow* window, const float& alpha, const Direction& moving) {
	if (type == AIR) return;

	sf::RectangleShape shape(sf::Vector2f(blockSize, blockSize));
	shape.setPosition((float) x * blockSize, (float) y * blockSize);

	if (type == PLAYER) {
		if (moving == UP) {
			shape.move(0, (-1 * blockSize * alpha) + blockSize);
		} else if (moving == DOWN) {
			shape.move(0, (blockSize * alpha) - blockSize);
		} else if (moving == LEFT) {
			shape.move((-1 * blockSize * alpha) + blockSize, 0);
		} else if (moving == RIGHT) {
			shape.move((blockSize * alpha) - blockSize, 0);
		}

		shape.setFillColor(sf::Color::Cyan);
	} else if (type == FRUIT) {
		shape.setFillColor(sf::Color::Green);
	} else if (type == OBSTACLE) {
		shape.setFillColor(sf::Color::Red);
	} else if (type == VISITED) {
		shape.setFillColor(sf::Color::Magenta);
	}

	window->draw(shape);
}

Tile::Tile(): x(0), y(0), type(AIR) {}
Tile::Tile(int x, int y, BlockType type): x(x), y(y), type(type) {}

int Tile::getX() const {
	return x;
}

int Tile::getY() const {
	return y;
}

BlockType Tile::getType() const {
	return type;
}

void Tile::setType(BlockType blockType) {
	Tile::type = blockType;
}

void Tile::setX(int newX) {
	Tile::x = newX;
}

void Tile::setY(int newY) {
	Tile::y = newY;
}

bool PathfinderTile::isFirst() const {
	return previous == this;
}

PathfinderTile &PathfinderTile::getPrevious() const {
	return *previous;
}

void PathfinderTile::setPrevious(PathfinderTile* previous) {
	PathfinderTile::previous = previous;
}

PathfinderTile::PathfinderTile(int x, int y, PathfinderTile* previous) : Tile(x, y, AIR),
																						 previous(previous) {}
PathfinderTile::PathfinderTile(int x, int y) : Tile(x, y, AIR) {}

std::list<PathfinderTile> PathfinderTile::getAdjacentTiles(const Game& game) {
	int offsetX[] = { 1, 0, -1, 0 };
	int offsetY[] = { 0, 1, 0, -1 };

	std::list<std::pair<int, int>> queue;
	std::list<PathfinderTile> list;

	for (int i = 0; i < 4; i++) {
		int newX = getX() + offsetX[i];
		int newY = getY() + offsetY[i];

		queue.emplace_back(newX, newY);
	}

	while (!queue.empty()) {
		std::pair<int, int> position = queue.front();
		int newX = position.first;
		int newY = position.second;
		queue.pop_front();

		if (newY < 0) {
			queue.emplace_back(newX, height - 1);
		} else if (newX < 0) {
			queue.emplace_back(width - 1, newY);
		} else if (newY >= height) {
			queue.emplace_back(newX, 0);
		} else if (newX >= width) {
			queue.emplace_back(0, newY);
		} else if (game.map[newX][newY].getType() != OBSTACLE) {
			list.emplace_back(newX, newY, this);
		}
	}

	return list;
}