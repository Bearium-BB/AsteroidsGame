#ifndef SAUCERMANAGER_H
#define SAUCERMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"
#include "Saucer.h"

class SaucerManager
{
    public:
        std::vector<Saucer> saucers;

        SaucerManager();
 
        void PlayerToSaucerCollision(Player& player);
        void Update();
        void Draw();
};

#endif
