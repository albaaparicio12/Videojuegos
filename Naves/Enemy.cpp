#include "Enemy.h"

Enemy::Enemy(string filename, float x, float y, Game* game)
	: Actor(filename, x, y, 36, 40, game) {

	vx = vxIntelligence;
	state = States::IDLE;
	audioShoot = new Audio("res/efecto_disparo.wav", false);
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
		if (vx == 0 ) {
			vxIntelligence *= -1;
			vx = vxIntelligence;
		}
		if (collisionDown) {
			if (outRight) {
				// mover hacia la izquierda vx tiene que ser negativa
				if (vxIntelligence > 0) {
					vxIntelligence = vxIntelligence * -1;
				}
				vx = vxIntelligence;
			}
			if (outLeft) {
				// mover hacia la derecha vx tiene que ser positiva
				if (vxIntelligence < 0) {
					vxIntelligence = vxIntelligence * -1;
				}
				vx = vxIntelligence;
			}
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

