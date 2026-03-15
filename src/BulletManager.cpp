#include <vector>
#include "BulletManager.h"
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include "PolygonCollision.h"
#include <iostream>
#include "raymath.h"
#include "Bullet.h"

BulletManager::BulletManager() {}

float BulletManager::BulletToAsteroidCollision(AsteroidManager& asteroidManager)
{
    float score = 0.0f;

    for (int i = (int)asteroidManager.asteroids.size() - 1; i >= 0; i--)
    {
        auto asteroidPoly = asteroidManager.asteroids[i].GetWorldVertices();

        for (int j = (int)bullets.size() - 1; j >= 0; j--)
        {
            auto bulletPoly = bullets[j].GetWorldVertices();

            if (CheckPolygonCollision(bulletPoly, asteroidPoly))
            {
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,
                                            asteroidManager.asteroids[i].size);
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,
                                            asteroidManager.asteroids[i].size);
                asteroidManager.asteroids.erase(asteroidManager.asteroids.begin() + i);
                bullets.erase(bullets.begin() + j);
                score += 1000.0f;
                break;
            }
        }
    }
    return score;
}

float BulletManager::SaucerBulletToPlayerCollision(Player* player)
{
    float score = 0.0f;
    auto  playerPoly = player->GetWorldVertices();

    for (int j = (int)bullets.size() - 1; j >= 0; j--)
    {
        if (bullets[j].tag != "saucer") continue;

        auto bulletPoly = bullets[j].GetWorldVertices();

        if (CheckPolygonCollision(bulletPoly, playerPoly))
        {
            player->TookDamage();
            bullets.erase(bullets.begin() + j);
            score += 1000.0f;
        }
    }
    return score;
}

void BulletManager::PlayerBulletToSaucerCollision(SaucerManager& saucerManager)
{
    for (int i = (int)saucerManager.saucers.size() - 1; i >= 0; i--)
    {
        if (i >= (int)saucerManager.saucers.size()) continue;
        auto saucerPoly = saucerManager.saucers[i].GetWorldVertices();

        for (int j = (int)bullets.size() - 1; j >= 0; j--)
        {
            if (j >= (int)bullets.size()) continue;
            if (bullets[j].tag != "player") continue;

            auto bulletPoly = bullets[j].GetWorldVertices();

            if (CheckPolygonCollision(bulletPoly, saucerPoly))
            {
                saucerManager.saucers.erase(saucerManager.saucers.begin() + i);
                bullets.erase(bullets.begin() + j);
                break;
            }
        }
    }
}

void BulletManager::Update()
{
    for (auto& b : bullets)
        b.Update();

    for (int i = (int)bullets.size() - 1; i >= 0; i--)
    {
        if (bullets[i].timer < 0.0f)
            bullets.erase(bullets.begin() + i);
    }
}

void BulletManager::Draw()
{
    for (auto& b : bullets)
        b.Draw();
}

void BulletManager::AddBullet(Bullet bullet)
{
    bullets.push_back(bullet);
}
