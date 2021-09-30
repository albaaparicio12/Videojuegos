#include "Enemy.h"

Enemy::Enemy(float x, float y, Game* game)
	: Actor("res/enemigo.png", x, y, 36, 40, game) {

	vx = 1;
	vxIntelligence = -1;
	vx = vxIntelligence;

	state = States::IDLE;

	aDying = new Animation("res/enemigo_morir.png", width, height,
		280, 40, 6, 8, false, game);
	aMoving = new Animation("res/enemigo_movimiento.png", width, height,
		108, 40, 6, 3, true, game);
	animation = aMoving;

}

void Enemy::update() {
	bool endAnimation = animation->update();
	if (endAnimation) {
		if (state == States::DYING) {
			state = States::DEAD;
		}
	}
	if (state == States::IDLE) {
		animation = aMoving;
	}
	if (state == States::DYING) {
		animation = aDying;
	}

	// Establecer velocidad
	if (state != States::DYING) {
		// no está muerto y se ha quedado parado
		if (vx == 0) {
			vxIntelligence *= -1;
			vx = vxIntelligence;
		}
	}
	else {
		vx = 0;
	}


}

void Enemy::draw(float scrollX) {
	animation->draw(x-scrollX, y);
}

void Enemy::impacted() {
	if (state != States::DYING) {
		state = States::DYING;
	}
}
