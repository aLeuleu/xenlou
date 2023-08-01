#include <algorithm>
#include <iostream>

#include <SDL.h>

#define SCREEN_WIDTH    800
#define SCREEN_HEIGHT   600
SDL_Rect create_rect();

int main(int argc, char* argv[]) {
	// Unused argc, argv
	(void) argc;
	(void) argv;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("xenlou",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(3000);

	return (0);
}