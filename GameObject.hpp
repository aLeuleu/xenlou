#pragma once // include guard
#include "Game.hpp"

class GameObject {
public:
	GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int _xpos;
	int _ypos;

	SDL_Texture *_objTexture;
	SDL_Rect _srcRect, _destRect;
	SDL_Renderer *_renderer;
};