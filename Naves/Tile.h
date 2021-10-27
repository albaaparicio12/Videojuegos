#pragma once
#include "Actor.h"

class Tile : public Actor
{
public:
	Tile(string filename,bool isDestruible, int x, int y, Game* game);
	bool isDestruible;
};

