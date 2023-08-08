#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char *textureSheet, SDL_Renderer *ren, int x, int y) {
	_renderer = ren;
	_objTexture = TextureManager::LoadTexture(textureSheet, ren);
	_xpos = x;
	_ypos = y;
}

void GameObject::Update() {
	_xpos++;
	_ypos++;

	_srcRect.h= 32;
	_srcRect.w = 32;
	_srcRect.x = 0;
	_srcRect.y = 0;

	_destRect.x = _xpos;
	_destRect.y = _ypos;
	_destRect.w = _srcRect.w * 2;
	_destRect.h = _srcRect.h * 2;
}

void GameObject::Render() {

	SDL_RenderCopy(_renderer, _objTexture, &_srcRect, &_destRect);

}