#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include "PolygonCollision.h"
#include <iostream>
#include "raymath.h"

AsteroidManager::AsteroidManager()
{
    asteroids.resize(0);
}

void AsteroidManager::PlayerToAsteroidCollision(Player& player)
{
    auto playerPoly = player.GetWorldVertices();

    for (int i = (int)asteroids.size() - 1; i >= 0; i--)
    {
        auto asteroidPoly = asteroids[i].GetWorldVertices();

        if (CheckPolygonCollision(playerPoly, asteroidPoly))
        {
            if (!player.isInvincible)
            {
                AddAsteroid(asteroids[i].position, asteroids[i].size);
                AddAsteroid(asteroids[i].position, asteroids[i].size);
                asteroids.erase(asteroids.begin() + i);
            }
            player.TookDamage();
        }
    }
}

void AsteroidManager::Update()
{
    for (int i = (int)asteroids.size() - 1; i >= 0; i--)
    {
        asteroids[i].Update();
        if (asteroids[i].size < 5.0f)
            asteroids.erase(asteroids.begin() + i);
    }
}

void AsteroidManager::Draw()
{
    for (auto& a : asteroids)
        a.Draw();
}

void AsteroidManager::GameOver()
{
    asteroids.clear();
    asteroids.resize(10);
}

void AsteroidManager::AddAsteroid(Vector2 position, float parentSize)
{
    asteroids.push_back(Asteroid(position, parentSize));
}
