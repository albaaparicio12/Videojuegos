#include "GameLayer.h"

GameLayer::GameLayer(Game* game)
	: Layer(game) {
	//llama al constructor del padre : Layer(renderer)
	init();
}

void GameLayer::init() {
	points = 0;
	player = new Player(50, 50, game);
	background = new Background("res/fondo.png", WIDTH * 0.5, HEIGHT * 0.5, -1, game);
	backgroundPoints = new Actor("res/icono_puntos.png", WIDTH * 0.85, HEIGHT * 0.05, 24, 24, game);
	textPoints = new Text("0", WIDTH * 0.9, HEIGHT * 0.05, game);

	backgroundLives = new Actor("res/icono_vidas2.png", WIDTH * 0.7, HEIGHT * 0.07, 40, 40, game);
	textLives = new Text(to_string(player->lives), WIDTH * 0.78, HEIGHT * 0.05, game);

	audioBackground = new Audio("res/musica_ambiente.mp3", true);
	audioBackground->play();

	projectiles.clear(); // Vaciar por si reiniciamos el juego
	projectilesEnemies.clear();
	enemies.clear(); // Vaciar por si reiniciamos el juego
}

void GameLayer::processControls() {
	// obtener controles
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		keysToControls(event);
	}
	//procesar controles
	// Disparar
	if (controlShoot) {
		Projectile* newProjectile = player->shoot();
		if (newProjectile != NULL) {
			projectiles.push_back(newProjectile);
		}

	}
	// Eje X
	if (controlMoveX > 0) {
		player->moveX(1);
	}
	else if (controlMoveX < 0) {
		player->moveX(-1);
	}
	else {
		player->moveX(0);
	}

	// Eje Y
	if (controlMoveY > 0) {
		player->moveY(1);
	}
	else if (controlMoveY < 0) {
		player->moveY(-1);
	}
	else {
		player->moveY(0);
	}

}

void GameLayer::keysToControls(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		game->loopActive = false;
		return;
	}
	if (event.type == SDL_KEYDOWN) {
		int code = event.key.keysym.sym;
		// Pulsada
		switch (code) {
		case SDLK_ESCAPE:
			game->loopActive = false;
			break;
		case SDLK_1:
			game->scale();
			break;
		case SDLK_d: // derecha
			controlMoveX = 1;
			break;
		case SDLK_a: // izquierda
			controlMoveX = -1;
			break;
		case SDLK_w: // arriba
			controlMoveY = -1;
			break;
		case SDLK_s: // abajo
			controlMoveY = 1;
			break;
		case SDLK_SPACE: // dispara
			controlShoot = true;
			break;
		}
	}
	if (event.type == SDL_KEYUP) {
		int code = event.key.keysym.sym;
		// Levantada
		switch (code) {
		case SDLK_d: // derecha
			if (controlMoveX == 1) {
				controlMoveX = 0;
			}
			break;
		case SDLK_a: // izquierda
			if (controlMoveX == -1) {
				controlMoveX = 0;
			}
			break;
		case SDLK_w: // arriba
			if (controlMoveY == -1) {
				controlMoveY = 0;
			}
			break;
		case SDLK_s: // abajo
			if (controlMoveY == 1) {
				controlMoveY = 0;
			}
			break;
		case SDLK_SPACE: // dispara
			controlShoot = false;
			break;
		}
	}
}

void GameLayer::update() {
	background->update();
	// Generar enemigos
	newEnemyTime--;
	newDifficultEnemyTime--;
	if (newEnemyTime <= 0) {
		int rX = (rand() % (600 - 500)) + 1 + 500;
		int rY = (rand() % (300 - 60)) + 1 + 60;
		enemies.push_back(new GreyEnemy(rX, rY, game));		
		newEnemyTime = 110 - killedEnemies * 2;
	}
	if (newDifficultEnemyTime <= 0) {
		int rX = (rand() % (600 - 500)) + 1 + 500;
		int rY = (rand() % (300 - 60)) + 1 + 60;
		enemies.push_back(new RedEnemy(rX, rY, game));
		newDifficultEnemyTime = 250 - killedEnemies * 2;
	}

	player->update();
	for (auto const& enemy : enemies) {
		enemy->update();
		ProjectileEnemy* newProjectile = enemy->shoot();
		if (newProjectile != NULL) {
			projectilesEnemies.push_back(newProjectile);
		}
	}

	for (auto const& projectile : projectiles) {
		projectile->update();
	}

	for (auto const& projectileEnemie : projectilesEnemies) {
		projectileEnemie->update();
	}

	// Colisiones
	for (auto const& enemy : enemies) {
		if (player->isOverlap(enemy)) {
			enemies.remove(enemy);
			if (player->lives > 1) {
				player->getShoot();
				textLives->content = to_string(player->lives);
			}
			else
				init();
			return; // Cortar el for
		}
	}

	// Colisiones , Enemy - Projectile

	list<Enemy*> deleteEnemies;
	list<Projectile*> deleteProjectiles;

	for (auto const& projectile : projectiles) {
		if (projectile->isInRender() == false) {

			bool pInList = std::find(deleteProjectiles.begin(),
				deleteProjectiles.end(),
				projectile) != deleteProjectiles.end();

			if (!pInList) {
				deleteProjectiles.push_back(projectile);
			}
		}
	}

	for (auto const& enemy : enemies) {
		for (auto const& projectile : projectiles) {
			if (enemy->isOverlap(projectile)) {
				bool pInList = std::find(deleteProjectiles.begin(),
					deleteProjectiles.end(),
					projectile) != deleteProjectiles.end();

				if (!pInList) {
					deleteProjectiles.push_back(projectile);
				}

				bool eInList = std::find(deleteEnemies.begin(),
					deleteEnemies.end(),
					enemy) != deleteEnemies.end();

				if (!eInList) {
					enemy->getShoot();
					if (enemy->lives <= 0) {
						deleteEnemies.push_back(enemy);
						killedEnemies++;
						points++;
						textPoints->content = to_string(points);
					}
				}
			}
		}
	}

	for (auto const& delEnemy : deleteEnemies) {
		enemies.remove(delEnemy);
	}
	deleteEnemies.clear();

	for (auto const& delProjectile : deleteProjectiles) {
		projectiles.remove(delProjectile);
	}
	deleteProjectiles.clear();


	cout << "update GameLayer" << endl;
}

void GameLayer::draw() {
	background->draw();
	for (auto const& projectile : projectiles) {
		projectile->draw();
	}
	for (auto const& projectileEnemie : projectilesEnemies) {
		projectileEnemie->draw();
	}

	player->draw();
	for (auto const& enemy : enemies) {
		enemy->draw();
	}

	backgroundPoints->draw();
	textPoints->draw();
	backgroundLives->draw();
	textLives->draw();

	SDL_RenderPresent(game->renderer); // Renderiza
}
