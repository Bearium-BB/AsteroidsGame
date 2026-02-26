#include <vector>
#include "BulletManager.h"
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include <stdio.h>
#include <iostream>
#include "raymath.h"
#include "Bullet.h"


BulletManager::BulletManager(){

}

float BulletManager::BulletToAsteroidCollision(AsteroidManager& asteroidManager){
    float score;
    for (int i = asteroidManager.asteroids.size() - 1; i >= 0; i--)
    {
        for (int j = bullets.size() - 1; j >= 0; j--)        
        {
            if(CheckCollisionCircles(bullets[j].position, bullets[j].size, asteroidManager.asteroids[i].position, asteroidManager.asteroids[i].size)){
                asteroidManager.asteroids.erase(asteroidManager.asteroids.begin() + i);
                bullets.erase(bullets.begin() + j);
                score += 10000;
            }
        }
    }   
    return 0; 
}

void BulletManager::Update(){
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update();
    }

    
    for (int i = 0; i < bullets.size(); i++)
    {
        if(bullets[i].timer < 0){
            bullets.erase(bullets.begin() + i);
        }
    }
    

}

void BulletManager::Draw(){
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw();
    }

}

void BulletManager::AddBullet(Bullet bullet){
    bullets.push_back(bullet);
}