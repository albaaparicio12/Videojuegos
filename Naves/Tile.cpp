#include "Tile.h"

Tile::Tile(string filename,bool destruible,bool jump, int x, int y, Game* game)
	: Actor(filename, x, y, 40, 32, game) {
	
	isDestruible = destruible;
	isJump = jump;
}
