#include "Player.h"

Player::Player(float x, float y, Game* game)
	: Actor("res/jugador.png", x, y, 35, 35, game) {

	audioShoot = new Audio("res/efecto_disparo.wav", false);
	
	aIdleRight = new Animation("res/jugador_idle_derecha.png", width, height,
		320, 40, 6, 8, game);
	aIdleLeft = new Animation("res/jugador_idle_izquierda.png", width, height,
		320, 40, 6, 8, game);
	aRunningLeft = new Animation("res/jugador_corriendo_izquierda.png", width, height,
		320, 40, 6, 8, game);
	aRunningRight = new Animation("res/jugador_corriendo_derecha.png", width, height,
		320, 40, 6, 8, game);

	animation = aIdleRight;

}

void Player::update() {
	animation->update();

	if (shootTime > 0) {
		shootTime--;
	}

	//Update orientation
	if (vx > 0) {
		orientation = Orientation::RIGHT;
	}else if (vx < 0) {
		orientation = Orientation::LEFT;
	}
	
	//Update state
	if (vx != 0) {
		state = States::MOVING;
	}
	else {
		state = States::IDLE;
	}
	
	//Update animation
	switch (state)
	{
	case (States::MOVING):
		if (orientation == Orientation::RIGHT)
			animation = aRunningRight;
		if (orientation == Orientation::LEFT)
			animation = aRunningLeft;
		break;
	default:
		animation = orientation == Orientation::RIGHT ? aIdleRight : aIdleLeft;
		break;
	}
	
	x = x + vx;
	y = y + vy;
}

void Player::moveX(float axis) {
	vx = axis * 3;
}

void Player::moveY(float axis) {
	vy = axis * 3;
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

void Player::draw() {
	animation->draw(x, y);
}

