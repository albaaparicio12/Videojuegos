#pragma once
#include "Actor.h"

class Coin : public Actor
{
	Coin(float x, float y, Game* game);
	void update();

};

