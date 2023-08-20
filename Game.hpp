#ifndef GAME_HPP
#define GAME_HPP

#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.hpp"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char *title, int xpos, int ypos, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	SDL_Renderer *getRenderer() { return renderer; }
	unsigned int getScreenWidth() { return _screenWidth; }
	unsigned int getScreenHeight() { return _screenHeight; }


	bool running() { return isRunning; }
	private:
		bool isRunning = false;
		SDL_Window *window;
		SDL_Renderer *renderer;
		unsigned int _screenWidth = 1500;
		unsigned int _screenHeight = 1000;
};

#endif	// GAME_HPP