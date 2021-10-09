#pragma once

#include "Actor.h"
#include "Animation.h"
#include "ProjectileEnemy.h"
#include "Audio.h"

class Enemy : public Actor
{
public:
	Enemy(string filename, float x, float y, Game* game);
	void update();
	void draw() override;
	void getShoot();
	ProjectileEnemy* shoot();
	Audio* audioShoot;
	int lives;

	Animation* aMoving;
	Animation* animation;
};
