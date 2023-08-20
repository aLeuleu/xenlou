#include "SDL.h"
#include <iostream>
#include "colors.h"

enum types {
	grass,
	water
};


class Tile
{
public:
	Tile();
	~Tile();
	Tile(int x, int y);
	void render(SDL_Renderer *renderer);
	void setPos(unsigned int x, unsigned int y);
	void setType(int i);
	types getType();
private:
	SDL_Point	_pos;
	int			_tileSize = 5;
	int	_type = grass;

	void drawSquare(SDL_Renderer *renderer) const;
};