#include <unistd.h>
#include "Game.hpp"
#include "GameObject.hpp"
#include "Map.hpp"
Map *map;
Game::Game() {}
Game::~Game() {}
void Game::init(const char *title, int xpos, int ypos, bool fullscreen) {
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, _screenWidth, _screenHeight, flags);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
			SDL_SetRenderDrawColor(renderer, WHITE);
		isRunning = true;
	}
	map = new Map(1000, 800, this, _scale);
}
void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT: isRunning = false;
			break;
		default: break;
	}
}
void Game::update() {
//change game scale according to keyboard input
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	//if the key pressed is F1..F4 key, change the scale
	if (state[SDL_SCANCODE_F1]) {
		_scale = 1;
		map->setScale(_scale);
	}
	if (state[SDL_SCANCODE_F2]) {
		_scale = 2;
		map->setScale(_scale);
	}
	if (state[SDL_SCANCODE_F3]) {
		_scale = 5;
		map->setScale(_scale);
	}
	if (state[SDL_SCANCODE_F4]) {
		_scale = 10;
		map->setScale(_scale);
	}
	map->update();
}
void Game::render() {
	SDL_RenderClear(renderer);
	map->render();
	SDL_SetRenderDrawColor(renderer, WHITE);
	SDL_RenderPresent(renderer);
}
void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!" << std::endl;
}
