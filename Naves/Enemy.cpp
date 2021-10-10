#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, Game* game)
	: Actor(filename, x, y, 36, 40, game) {
	
	vx = 1;
	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, game);
	animation = aMoving;
}

void Enemy::update() {
	animation->update();
	if (shootTime > 0) {
		shootTime--;
	}
	vx = -1;
	x = x + vx;
}

void Enemy::draw() {
	animation->draw(x, y);
}

void Enemy::getShoot() {
	lives--;
}

ProjectileEnemy* Enemy::shoot() {
	if (shootTime == 0) {
		shootTime = shootCadence;
		audioShoot->play();
		return new ProjectileEnemy(x, y, game);
	}
	else return NULL;
}