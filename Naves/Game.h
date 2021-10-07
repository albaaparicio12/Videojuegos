#pragma once

// Todas las librerias de SDL y otras utilidades
#include <iostream>
#include <string>
using namespace std;
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map> 

// Valores generales
#define WIDTH 480
#define HEIGHT 320

#include "Layer.h"
class Layer;

class Game
{
public:
	Game();
	void loop();
	void scale();
	bool scaledToMax = false;
	float scaleLower = 1;
	SDL_Texture* getTexture(string filename);
	map<string, SDL_Texture*> mapTextures; // map - cache


	TTF_Font* font;

	SDL_Window* window; // ventana
	SDL_Renderer* renderer; // renderizador
	bool loopActive; // Juego activo
	Layer* gameLayer;

	int currentLevel = 0;
	int finalLevel = 2;

	int input;
	int const inputKeyboard = 1;
	int const inputMouse = 2;
	int const inputGamePad = 3;
};

enum class States {
	IDLE,
	MOVING,
	JUMPING,
	DYING,
	DEAD,
	SHOOTING
};

enum class Orientation {
	RIGHT,
	LEFT
};