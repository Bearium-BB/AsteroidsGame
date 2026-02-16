#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Actor.h"

class Player : public Actor {
public:

    Vector2 p1;
    Vector2 p2;
    Vector2 p3;
    Vector2 center;

    double angle;
    float maxSpeed;
    float dt;
    float forwardSpeed;
    float rotationSpeed;

    Player();              

    void Update();
    void UpdatePosition();
    void Draw();
    void Wrapping(); 
    void TookDamage();
};

#endif
