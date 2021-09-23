#pragma once

#include "Actor.h"
#include "Animation.h"

class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void update();
	void draw() override;
	void impacted(); // Recibe impacto y pone animaci�n de morir
	
	States state = States::IDLE;
	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
};
