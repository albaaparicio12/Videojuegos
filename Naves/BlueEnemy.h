#pragma once
#include "Enemy.h"
class BlueEnemy :
    public Enemy
{
public:
    BlueEnemy(float x, float y, Game* game);
    ProjectileEnemy* shoot() override;
    void update() override;
};

