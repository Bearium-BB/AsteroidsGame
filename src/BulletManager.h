#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"
#include "AsteroidManager.h"
#include "Bullet.h"

class BulletManager
{
    public:
        std::vector<Bullet> bullets;
        float score;

        BulletManager();

        float BulletToAsteroidCollision(AsteroidManager& asteroidManager);
        void Update();
        void Draw();
        void AddBullet(Bullet bullet);
};

#endif
