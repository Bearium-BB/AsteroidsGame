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
    float score = 0;
    float newLifeScore = 0;
    float saucerScore = 0;
    float smallSaucerTimer = 0;
    float dt = 0;
    float nextAsteroid = 0;
    int currentLevel = 0;

    Music music;
    Saucer testSaucer;

    GameMode();

    void Update();
    void Draw();
    void NextLevel();
};

#endif
