#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player {
public:
    Vector2 position;
    Vector2 velocity;

    Vector2 p1;
    Vector2 p2;
    Vector2 p3;
    Vector2 center;

    double angle;
    float maxSpeed;

    Player();              

    void Update();
    void UpdatePosition();
    void Draw();
    void Wrapping(); 
};

#endif
