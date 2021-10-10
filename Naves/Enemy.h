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
	int shootCadence = 130;
	int shootTime = 0;

	Audio* audioShoot;
	int lives;

	Animation* aMoving;
	Animation* animation;
};
