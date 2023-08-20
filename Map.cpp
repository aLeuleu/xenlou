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

Map::Map(unsigned int width, unsigned int height, Game *game) {
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
			_tiles[x + y * _width].setPos(x, y);
		}
	}

	//generate the map
	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			_tiles[x + y * _width].setType(grass);
		}
	}

	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			if (rand() % 100 < 30) {
				_tiles[x + y * _width].setType(water);
			}
		}
	}

	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			if (_tiles[x + y * _width].getType() == water) {
				// if all neighbors are water, change to water
				if (x > 0 && _tiles[(x - 1) + y * _width].getType() == water &&
					x < _width - 1 && _tiles[(x + 1) + y * _width].getType() == water &&
					y > 0 && _tiles[x + (y - 1) * _width].getType() == water &&
					y < _height - 1 && _tiles[x + (y + 1) * _width].getType() == water) {
					_tiles[x + y * _width].setType(water);
				}
			}
		}
	}

	for (unsigned int y = 0; y < _height; y++) {
		for (unsigned int x = 0; x < _width; x++) {
			if (_tiles[x + y * _width].getType() == water) {
				// if all neighbors are grass, change to grass
				if (x > 0 && _tiles[(x - 1) + y * _width].getType() == grass &&
					x < _width - 1 && _tiles[(x + 1) + y * _width].getType() == grass &&
					y > 0 && _tiles[x + (y - 1) * _width].getType() == grass &&
					y < _height - 1 && _tiles[x + (y + 1) * _width].getType() == grass) {
					_tiles[x + y * _width].setType(grass);
				}
			}
		}
	}

	_initialized = true;
}

