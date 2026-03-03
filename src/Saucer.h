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

        Player* player;
        BulletManager* bulletManager;

        Saucer();
        Saucer(Player* currentPlayer, BulletManager* bulletManagerTest);   
        void Update();
        void Draw();
        void Wrapping(); 

};

#endif
