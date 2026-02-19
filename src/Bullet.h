#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "Actor.h"

class Bullet : public Actor {
public:

    float speed;
    float size;
    float timer;
    float dt;

    Bullet(float x , float y, double angle);

    void Update();
    void Draw();
    void Wrapping();      
};

#endif
