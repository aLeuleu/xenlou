#include "SDL.h"
#include "Map.hpp"

Map::Map() {
}

Map::~Map() {
}

void Map::render() {
	static int count = 0;
	count++;
	if (!_initialized)
		return;
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			_tiles[x + y * _width].render(_renderer);
		}
	}
}

Map::Map(unsigned int width, unsigned int height, Game *game, char scale) {
	_width = width;
	_height = height;
	_renderer = game->getRenderer();
	_screenHeight = game->getScreenHeight();
	_screenWidth = game->getScreenWidth();
	_tiles = new Tile[_width * _height]; // access a tile with _tiles[x + y * _width]
	//generate a seed
	_seed = SDL_GetTicks(); //here we use the time in milliseconds since the program started as a seed
	srand(_seed);  //initialize the random number generator with the seed
	//displaying the seed
	std::cout << "Seed: " << _seed << std::endl;
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			//set scale
			_tiles[x + y * _width].setScale(scale);
			_tiles[x + y * _width].setPos(x, y);
		}
	}

	//generate the map
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			_tiles[x + y * _width].setType(alive);
		}
	}
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			if (rand() % 100 < 50) {
				_tiles[x + y * _width].setType(dead);
			}
		}
	}
	_initialized = true;
}

void Map::update() {
	//Rules of game of life here
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			int aliveNeighbors = 0;
			if (x > 0 && _tiles[(x - 1) + y * _width].getType() == alive)
				aliveNeighbors++;
			if (x < _width - 1 && _tiles[(x + 1) + y * _width].getType() == alive)
				aliveNeighbors++;
			if (y > 0 && _tiles[x + (y - 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (y < _height - 1 && _tiles[x + (y + 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (x > 0 && y > 0 && _tiles[(x - 1) + (y - 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (x < _width - 1 && y > 0 && _tiles[(x + 1) + (y - 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (x > 0 && y < _height - 1 && _tiles[(x - 1) + (y + 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (x < _width - 1 && y < _height - 1 && _tiles[(x + 1) + (y + 1) * _width].getType() == alive)
				aliveNeighbors++;
			if (_tiles[x + y * _width].getType() == alive) {
				if (aliveNeighbors < 2 || aliveNeighbors > 3)
					_tiles[x + y * _width].switchState();
			} else {
				if (aliveNeighbors == 3)
					_tiles[x + y * _width].switchState();
			}
		}
	}
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			_tiles[x + y * _width].update();
		}
	}
}
void Map::setScale(char i) {
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			_tiles[x + y * _width].setScale(i);
		}
	}
}
