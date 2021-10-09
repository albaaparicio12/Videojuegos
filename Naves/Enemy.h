#pragma once

#include "Actor.h"
#include "Animation.h"

class Enemy : public Actor
{
public:
	Enemy(string filename, float x, float y, Game* game);
	void update();
	void draw() override;
	void getShoot();
	int lives;

	Animation* aMoving;
	Animation* animation;
};
