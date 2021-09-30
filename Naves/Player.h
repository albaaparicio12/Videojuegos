#pragma once

#include "Actor.h"
#include "Projectile.h"
#include "Audio.h"
#include "Animation.h" 

class Player : public Actor
{
public:
	Player(float x, float y, Game* game);
	Projectile* shoot();
	void update();
	void moveX(float axis);
	void moveY(float axis);
	int shootCadence = 30;
	int shootTime = 0;
	Audio* audioShoot;
	void draw(float scrollX = 0) override; // Va a sobrescribir
	Animation* aIdleRight;
	Animation* aIdleLeft;
	Animation* aRunningRight;
	Animation* aRunningLeft;
	Animation* aShootingRight;
	Animation* aShootingLeft;
	Animation* animation; // Referencia a la animación mostrada
	
	Orientation orientation = Orientation::RIGHT;
	States state = States::IDLE;
	
	void jump();
	bool isOnAir;

};
