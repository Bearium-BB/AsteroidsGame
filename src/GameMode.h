#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"
#include <vector>
#include "Actor.h"
#include "AsteroidManager.h"
#include "BulletManager.h"
#include "Saucer.h"
#include "SaucerManager.h"
class GameMode {
public:
    Player* player;
    AsteroidManager asteroidManager;
    BulletManager bulletManager;
    SaucerManager saucerManager;
    float score;
    float newLifeScore;
    float saucerScore;

    Music music;
    Saucer testSaucer;

    GameMode();

    void Update();
    void Draw();
};

#endif
