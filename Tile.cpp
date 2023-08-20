
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
	SDL_SetRenderDrawColor(renderer, RED);

	SDL_Rect _rect;
	_rect.x = _pos.x * _tileSize;
	_rect.y = _pos.y * _tileSize;
	_rect.w = _tileSize;
	_rect.h = _tileSize;



	switch(_type)
	{
		case grass:
			SDL_SetRenderDrawColor(renderer, LIGHT_GREEN);
			break;
		case water:
			SDL_SetRenderDrawColor(renderer, LIGHT_BLUE);
			break;
	}



	SDL_RenderFillRect(renderer, &_rect);
	SDL_SetRenderDrawColor(renderer, LIGHT_GREY);
	SDL_RenderDrawRect(renderer, &_rect);

}


void Tile::setPos(unsigned int x, unsigned int y) {
	_pos.x = x;
	_pos.y = y;
}

void Tile::setType(int i) {
	_type = i;
}

types Tile::getType() {
	return (types)_type;
}

