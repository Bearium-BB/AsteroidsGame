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

        Player* player;

        Saucer();
        Saucer(Player* currentPlayer);   
        void Update();
        void Draw();
        void Wrapping(); 

};

#endif
