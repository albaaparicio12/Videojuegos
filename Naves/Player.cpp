#include "Player.h"

Player::Player(float x, float y, Game* game)
	: Actor("res/nave.png", x, y, 50, 57, game) {
	audioShoot = new Audio("res/efecto_disparo.wav", false);
}

void Player::update() {
	if (shootTime > 0) {
		shootTime--;
	}

	//Comprobar que no se sale de los límites
	if (x + vx > 0 + width / 2 && x + vx < WIDTH - width / 2)
		x = x + vx;
	if (y + vy > 0 + height / 2 && y + vy < HEIGHT - height / 2)
		y = y + vy;
}

void Player::moveX(float axis) {
	vx = axis * 3;
}

void Player::moveY(float axis) {
	vy = axis * 3;
}

void Player::getShoot() {
	lives--;
}

Projectile* Player::shoot() {
	if (shootTime == 0) {
		audioShoot->play();
		shootTime = shootCadence;
		return new Projectile(x, y, game);
	}
	else {
		return NULL;
	}

}
