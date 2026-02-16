#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"
#include <vector>
#include "Actor.h"
#include "AsteroidManager.h"

class GameMode {
public:
    Player player;
    AsteroidManager asteroidManager;

    GameMode();

    void Update();
    void Draw();
};

#endif
