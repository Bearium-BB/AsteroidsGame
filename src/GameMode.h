#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"
#include <vector>
#include "Actor.h"
#include "AsteroidManager.h"
#include "BulletManager.h"

class GameMode {
public:
    Player* player;
    AsteroidManager asteroidManager;
    BulletManager bulletManager;
    float score;
    float newLifeScore;
    Music music;

    GameMode();

    void Update();
    void Draw();
};

#endif
