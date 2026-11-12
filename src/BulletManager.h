#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H

#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "Player.h"
#include "AsteroidManager.h"
#include "Bullet.h"
#include "SaucerManager.h"

class BulletManager
{
    public:
        std::vector<Bullet> bullets;
        float score = 0;

        BulletManager();

        float BulletToAsteroidCollision(AsteroidManager& asteroidManager);
        float SaucerBulletToPlayerCollision(Player* player);
        void PlayerBulletToSaucerCollision(SaucerManager& saucerManager);
        void Update();
        void Draw();
        void AddBullet(Bullet bullet);
};

#endif
