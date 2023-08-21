#include "Tile.hpp"

Tile::Tile() {
	_pos.x = 0;
	_pos.y = 0;
}

Tile::~Tile() {
}

Tile::Tile(int x, int y) {
	_pos.x = x;
	_pos.y = y;
}

void Tile::render(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, BLACK);
	SDL_Rect _rect;
	_rect.x = _pos.x * _tileSize;
	_rect.y = _pos.y * _tileSize;
	_rect.w = _tileSize;
	_rect.h = _tileSize;
	switch (_type) {
		case alive: SDL_SetRenderDrawColor(renderer, PURPLE);
			break;
		case dead: SDL_SetRenderDrawColor(renderer, BLACK);
			break;
	}
	SDL_RenderFillRect(renderer, &_rect);
//	SDL_SetRenderDrawColor(renderer, LIGHT_GREY);
//	SDL_RenderDrawRect(renderer, &_rect);

}

void Tile::setPos(unsigned int x, unsigned int y) {
	_pos.x = x;
	_pos.y = y;
}

void Tile::setType(int i) {
	_type = i;
}

types Tile::getType() {
	return (types) _type;
}

void Tile::update() {
	if (_switchState) {
		_switchState = false;
		if (_type == alive)
			_type = dead;
		else
			_type = alive;
	}
}

void Tile::switchState() {
	_switchState = true;
}
void Tile::setScale(char i) {
	_tileSize = i * 2;
}
