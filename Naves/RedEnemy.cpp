#include "RedEnemy.h"
#include "Game.h"

RedEnemy::RedEnemy(float x, float y, Game* game)
	: Enemy("res/enemigo_Rojo.png", x, y, game) {
	
	lives = 3;
	vx = 3;
	aMoving = new Animation("res/enemigo_movimiento_rojo.png", width, height,
		108, 40, 6, 3, game);
	animation = aMoving;
	audioShoot = new Audio("res/efecto_disparo.wav", false);
}
