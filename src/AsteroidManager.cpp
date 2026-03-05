#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include <stdio.h>
#include <iostream>
#include "raymath.h"



AsteroidManager::AsteroidManager(){
    asteroids.resize(0);
}


void AsteroidManager::PlayerToAsteroidCollision(Player& player){
        for (int i = asteroids.size() - 1; i >= 0; i--)
        {
            if (CheckCollisionCircles(player.position, 28,
                                    asteroids[i].position,
                                    asteroids[i].size))
            {

                if(!player.isInvincible){
                    AddAsteroid(asteroids[i].position,asteroids[i].size);
                    AddAsteroid(asteroids[i].position,asteroids[i].size);

                    asteroids.erase(asteroids.begin() + i);
                }

                player.TookDamage();

            }
        }   
}

void AsteroidManager::Update(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Update();
        if(asteroids[i].size < 5){
            asteroids.erase(asteroids.begin() + i);
        }
    }

}

void AsteroidManager::Draw(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Draw();
    }

}


void AsteroidManager::GameOver(){
    asteroids.clear();
    asteroids.resize(10);
}

void AsteroidManager::AddAsteroid(Vector2 position,float parentSize){
    asteroids.push_back(Asteroid(position,parentSize));
}
