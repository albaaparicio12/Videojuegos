#include "BlueEnemy.h"
BlueEnemy::BlueEnemy(float x, float y, Game* game)
	: Enemy("res/enemigo_azul.png", x, y, game) {
	
	shootTime = 0;
	shootCadence = 130;

	vxIntelligence = -3;
	vx = 3;
	aMoving = new Animation("res/enemigo_movimiento_azul.png", width, height,
		108, 40, 6, 3,true, game);
	animation = aMoving;

	aDying = new Animation("res/enemigo_morir_azul.png", width, height,
		280, 40, 6, 8, false, game);
	
}

ProjectileEnemy* BlueEnemy::shoot() {
	if (shootTime == 0) {
		shootTime = shootCadence;
		audioShoot->play();
		auto projectile = new ProjectileEnemy(x, y, game);
		if (vxIntelligence > 0) {
			projectile->vx *= -1;
		}
		return projectile;
	}
	else return NULL;
}

void BlueEnemy::update() {
	if (shootTime > 0) {
		shootTime--;
	}
	Enemy::update();
	
}
