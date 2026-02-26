#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "Actor.h"
#include "Bullet.h"
#include <vector>

class BulletManager;

class Player : public Actor {
public:

    Vector2 p1;
    Vector2 p2;
    Vector2 p3;
    Vector2 center;
    BulletManager* bulletManager;
    float health;
    bool isInvincible;
    float elapsedTimeForIsInvincible;
    float isInvincibleTime;

    std::vector<Bullet> bullets;

    double angle;
    float maxSpeed;
    float dt;
    float forwardSpeed;
    float rotationSpeed;

    Player(BulletManager* bulletManagerTest);              

    void Update();
    void UpdatePosition();
    void Draw();
    void Wrapping(); 
    void TookDamage();
};

#endif
