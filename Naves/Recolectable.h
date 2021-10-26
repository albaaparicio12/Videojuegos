#pragma once
#include "Actor.h"
#include "Animation.h"
class Recolectable :
    public Actor
{
public:
    Recolectable(float x, float y, Game* game);
    Animation* aItem;
    void draw(float scrollX = 0) override;
    void update();
};

