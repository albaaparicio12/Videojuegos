#include "Recolectable.h"

Recolectable::Recolectable(float x, float y, Game* game)
	: Actor("res/icono_recolectable.png", x, y, 40, 40, game) {

	aItem = new Animation("res/recolectable.png",
		width, height, 256, 32, 2, 8, true, game);
}

void Recolectable::draw(float scrollX) {
	aItem->draw(x - scrollX, y);
}

void Recolectable::update() {
	aItem->update();
}