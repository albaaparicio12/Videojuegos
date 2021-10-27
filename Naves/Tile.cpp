#include "Tile.h"

Tile::Tile(string filename,bool destruible, int x, int y, Game* game)
	: Actor(filename, x, y, 40, 32, game) {
	
	isDestruible = destruible;
}
