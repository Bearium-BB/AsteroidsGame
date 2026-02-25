#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include <stdio.h>
#include <iostream>
#include "raymath.h"
#include "BulletManager.h"
#include "Bullet.h"

BulletManager::BulletManager(){
    bullets.resize(10);
}

void BulletManager::BulletToAsteroidCollision(AsteroidManager& asteroidManager){
    for (int i = 0; i < asteroidManager.asteroids.size(); i++)
    {
        for (int j = 0; j < asteroidManager.asteroids.size(); j++)
        {
            if(CheckCollisionCircles(bullets[j].position,28,asteroidManager.asteroids[i].position,asteroidManager.asteroids[i].size)){
            player.TookDamage();
            std::cout << player.velocity.x << " , "
                    << player.velocity.y << " : " 
                    << Vector2Length(player.velocity) << std::endl;
        }
        }
    }    
}

void BulletManager::Update(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Update();
    }

}

void BulletManager::Draw(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Draw();
    }

}