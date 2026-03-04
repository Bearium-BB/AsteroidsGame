#ifndef SAUCERMANAGER_H
#define SAUCERMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"
#include "Saucer.h"
#include "AsteroidManager.h"

class SaucerManager
{
    public:
        std::vector<Saucer> saucers;

        SaucerManager();
 
        void SaucerToAsteroidCollision(AsteroidManager& asteroidManager);
        void Update();
        void Draw();
        void AddSaucer(Saucer saucer);
};

#endif
