#ifndef SAUCERMANAGER_H
#define SAUCERMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"

class SaucerManager
{
    public:
        std::vector<Asteroid> saucers;

        SaucerManager();
 
        void PlayerToSaucerCollision(Player& player);
        void Update();
        void Draw();
        void GameOver();
        void AddAsteroid(Vector2 position, float parentSize);
};

#endif
