#include "Game.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

GameObject* player;
GameObject*	enemy;
Map* 		map;

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
	player = new GameObject("/Users/aurelienlevra/CLionProjects/xenlou/assets/player.png", renderer, 0, 0);
	enemy = new GameObject("/Users/aurelienlevra/CLionProjects/xenlou/assets/enemy.png", renderer, 50, 50);
	map = new Map(1000, 1000, this);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::update() {
	player->Update();
	enemy->Update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	player->Render();
	enemy->Render();
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
