#include "Game.hpp"
#include <SDL.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

Game *game = new Game();

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
			SDL_Delay(frameDelay - frameTime);
	}

	game->clean();

	return 0;
}