#pragma once

#include "Layer.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Projectile.h"
#include "ProjectileEnemy.h"
#include <list>
#include "Text.h"
#include "Audio.h" 
#include "GreyEnemy.h"
#include "RedEnemy.h"
#include "Coin.h"

class GameLayer : public Layer
{
public:
	GameLayer(Game* game);
	void init() override;
	void processControls() override;
	void update() override;
	void draw() override;
	void keysToControls(SDL_Event event);

	int newEnemyTime = 0;
	int newDifficultEnemyTime = 0;
	int killedEnemies = 0;

	Player* player;
	Background* background;
	bool controlShoot = false;
	int controlMoveY = 0;
	int controlMoveX = 0;

	list<Enemy*> enemies;
	list<Projectile*> projectiles;
	list<ProjectileEnemy*> projectilesEnemies;
	list<Coin*> coins;

	Actor* backgroundPoints;
	Text* textPoints;
	int points;

	Actor* backgroundLives;
	Text* textLives;

	Audio* audioBackground;

	int cointTime = 0;
};
