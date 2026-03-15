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
#include "Saucer.h"
#include "SaucerManager.h"

SaucerManager::SaucerManager()
{
    saucers.resize(0);
}

void SaucerManager::SaucerToAsteroidCollision(AsteroidManager& asteroidManager)
{
    for (int i = (int)asteroidManager.asteroids.size() - 1; i >= 0; i--)
    {
        auto asteroidPoly = asteroidManager.asteroids[i].GetWorldVertices();

        for (int j = (int)saucers.size() - 1; j >= 0; j--)
        {
            auto saucerPoly = saucers[j].GetWorldVertices();

            if (CheckPolygonCollision(saucerPoly, asteroidPoly))
            {
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,
                                            asteroidManager.asteroids[i].size);
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,
                                            asteroidManager.asteroids[i].size);
                asteroidManager.asteroids.erase(asteroidManager.asteroids.begin() + i);
                saucers.erase(saucers.begin() + j);
                break;
            }
        }
    }
}

void SaucerManager::Update()
{
    for (auto& s : saucers)
        s.Update();
}

void SaucerManager::Draw()
{
    for (auto& s : saucers)
        s.Draw();
}

void SaucerManager::AddSaucer(Saucer saucer)
{
    saucers.push_back(saucer);
}
