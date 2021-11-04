#pragma once
#include "Actor.h"

class Tile : public Actor
{
public:
	Tile(string filename,bool isDestruible,bool isJump, int x, int y, Game* game);
	bool isDestruible;
	bool isJump;
};

