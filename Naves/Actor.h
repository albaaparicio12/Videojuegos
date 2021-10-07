#pragma once

#include "Game.h"

class Actor
{
public:
	Actor(string filename, float x, float y, Game* game);
	Actor(string filename, float x, float y, int width, int height, Game* game);
	virtual void draw(float scrollX = 0);
	SDL_Texture* texture;
	bool isOverlap(Actor* actor);
	int x;
	int y;
	float vx;
	float vy;
	int width;
	int height;
	int fileWidth;
	int fileHeight;
	Game* game; // referencia al juego
	bool isInRender(float scrollX = 0);
	bool containsPoint(int pointX, int pointY); // contiene punto
	bool collisionDown;
	bool clicked; // Está pulsado

};
