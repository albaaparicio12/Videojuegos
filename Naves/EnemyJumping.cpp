#include "EnemyJumping.h"
EnemyJumping::EnemyJumping(float x, float y, Game* game)
	: Enemy("res/enemigo_naranja.png", x, y, game) {

	shootTime = 0;
	shootCadence = 130;

	vxIntelligence = -3;
	vx = 2;
	aMoving = new Animation("res/enemigo_movimiento_naranja.png", width, height,
		108, 40, 6, 3, true, game);
	animation = aMoving;

	aDying = new Animation("res/enemigo_morir_naranja.png", width, height,
		280, 40, 6, 8, false, game);

}

void EnemyJumping::update() {
	if (timeJump == 0) {
		vy = -8;
		timeJump = 50;
	}
	else
		timeJump--;
	Enemy::update();

}