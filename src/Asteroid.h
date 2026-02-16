#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"
#include "Actor.h"

class Asteroid : public Actor {
public:

    Vector2 direction;

    float maxSpeed;
    float dt;
    float speed;
    float size;

    Asteroid();
    void Update();
    void Draw();
    void Wrapping();      
};

#endif
