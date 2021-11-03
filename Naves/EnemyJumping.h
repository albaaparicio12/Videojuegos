#pragma once
#include "Enemy.h"
class EnemyJumping :
    public Enemy
{
public:
    EnemyJumping(float x, float y, Game* game);
    int timeJump = 0;
    void update() override;
};

