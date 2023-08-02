#include "Game.hpp"
#include <SDL.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600

Game *game = new Game();

int main(int argc, char* argv[]) {
	game->init("Game Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);

	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}