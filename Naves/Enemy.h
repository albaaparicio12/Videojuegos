#pragma once

#include "Actor.h"
#include "Animation.h"
#include "Game.h"
#include "ProjectileEnemy.h"
#include "Audio.h"

class Enemy : public Actor
{
public:
	Enemy(string filename, float x, float y, Game* game);
	virtual void update();
	void draw(float scrollX = 0) override;
	void impacted(); // Recibe impacto y pone animación de morir
	
	States state = States::IDLE;
	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
	virtual ProjectileEnemy* shoot() { return NULL; };
	Audio* audioShoot;

	int shootTime = 0;
	int shootCadence = 130;
	float vxIntelligence;
};
