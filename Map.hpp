#pragma once
#include "SDL.h"
#include "Game.hpp"
#include "Tile.hpp"

class Map
{
public:
	Map();
	Map(unsigned int width, unsigned int height, Game *game);
	~Map();
	void render();

private:
	bool 			_initialized = false;
	unsigned int 	_width = 0;
	unsigned int 	_height = 0;
	Tile			 *_tiles;
	SDL_Renderer	 *_renderer;
	unsigned int 	_screenWidth;
	unsigned int 	_screenHeight;
	int 			_seed = 0;
};