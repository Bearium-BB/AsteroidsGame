#ifndef ASTEROIDMANAGER_H
#define ASTEROIDMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"

class AsteroidManager
{
    public:
        std::vector<Asteroid> asteroids;

        AsteroidManager();

        void PlayerToAsteroidCollision(Player& player);
        void Update();
        void Draw();
};

#endif
