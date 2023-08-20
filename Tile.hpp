#include "SDL.h"
#include <iostream>
#include "colors.h"

enum types {
	alive,
	dead
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
	void update();
	void switchState();
private:
	SDL_Point	_pos;
	int			_tileSize = 2;
	int	_type = alive;
	bool 		_switchState = false;
};