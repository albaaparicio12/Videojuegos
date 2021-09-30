#pragma once

#include "Actor.h"
#include "Animation.h"
#include "Game.h"
class Enemy : public Actor
{
public:
	Enemy(float x, float y, Game* game);
	void update();
	void draw(float scrollX = 0) override;
	void impacted(); // Recibe impacto y pone animación de morir
	
	States state = States::IDLE;
	Animation* aDying;
	Animation* aMoving;
	Animation* animation;
};
