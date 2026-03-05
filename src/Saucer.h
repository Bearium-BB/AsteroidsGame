#ifndef SAUCER_H
#define SAUCER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"

class Saucer : public Actor
{
    public:
        float dt;
        float size;
        float timeToShoot = 3;

        float minSize = 10.0f;
        float maxSize = 100.0f;

        float minSpread = 1.0f;
        float maxSpread = 15.0f;

        bool smallSaucerImproveAim;

        Player* player;
        BulletManager* bulletManager;

        Saucer();
        Saucer(Player* currentPlayer, BulletManager* bulletManagerTest);   
        Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim);   
        Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim, float sizeSaucer);   
        void Update();
        void Draw();
        void Wrapping(); 

};

#endif
