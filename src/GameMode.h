#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "raylib.h"
#include "Player.h"
#include "Asteroid.h"
#include <vector>
#include "Actor.h"

class GameMode {
public:
    Player player;
    std::vector<Asteroid> asteroids;

    GameMode();

    void Update();
};

#endif
