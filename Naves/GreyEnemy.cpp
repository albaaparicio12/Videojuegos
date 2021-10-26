#include "GreyEnemy.h"

GreyEnemy::GreyEnemy(float x, float y, Game* game)
	: Enemy("res/enemigo.png", x, y, game) {

	vxIntelligence = -1;
	vx = 1;
	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3,true, game);
	animation = aMoving;

	aDying = new Animation("res/enemigo_morir.png", width, height,
		280, 40, 6, 8, false, game);
}

ProjectileEnemy* GreyEnemy::shoot() {
	return NULL;
}