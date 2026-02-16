#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"

class Asteroid {
public:
    Vector2 position;
    Vector2 velocity;
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
