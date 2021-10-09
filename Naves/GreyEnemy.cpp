#include "GreyEnemy.h"

GreyEnemy::GreyEnemy(float x, float y, Game* game)
	: Enemy("res/enemigo.png", x, y, game) {

	lives = 1;
	vx = 1;
	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, game);
	animation = aMoving;
	audioShoot = new Audio("res/efecto_disparo.wav", false);

}

