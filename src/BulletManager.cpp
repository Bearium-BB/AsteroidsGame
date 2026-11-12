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
    float score = 0;
    for (int i = asteroidManager.asteroids.size() - 1; i >= 0; i--)
    {
        for (int j = bullets.size() - 1; j >= 0; j--)        
        {
            if(CheckCollisionCircles(bullets[j].position, bullets[j].size, asteroidManager.asteroids[i].position, asteroidManager.asteroids[i].size)){
                
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,asteroidManager.asteroids[i].size);
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,asteroidManager.asteroids[i].size);  
                asteroidManager.asteroids.erase(asteroidManager.asteroids.begin() + i);
                bullets.erase(bullets.begin() + j);
                score += 1000;              
                break; // asteroid i was erased; do not index it again
            }
        }
    }   
    return score; 
}

float BulletManager::SaucerBulletToPlayerCollision(Player* player){
    float score = 0;

    for (int j = bullets.size() - 1; j >= 0; j--)        
    {
        if(CheckCollisionCircles(bullets[j].position, bullets[j].size, player->position, 28)){
            if(bullets[j].tag == "saucer")
            {
                player->TookDamage();
                bullets.erase(bullets.begin() + j);
                score += 1000;    
            }          
        }
    }
    return score; 
}

void BulletManager::PlayerBulletToSaucerCollision(SaucerManager& saucerManager) {
    for (int i = (int)saucerManager.saucers.size() - 1; i >= 0; i--)
    {
        if (i >= (int)saucerManager.saucers.size()) continue;

        for (int j = (int)bullets.size() - 1; j >= 0; j--)
        {
            if (j >= (int)bullets.size()) continue;

            if (CheckCollisionCircles(
                    bullets[j].position, bullets[j].size,
                    saucerManager.saucers[i].position, saucerManager.saucers[i].size))
            {
                if (bullets[j].tag  == "player") {
                    saucerManager.saucers.erase(saucerManager.saucers.begin() + i);
                    bullets.erase(bullets.begin() + j);
                    break;
                }
            }
        }
    }
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