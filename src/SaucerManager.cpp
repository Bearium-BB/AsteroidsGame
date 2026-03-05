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
#include "Saucer.h"
#include "SaucerManager.h"

SaucerManager::SaucerManager(){
    saucers.resize(0);
}

void SaucerManager::SaucerToAsteroidCollision(AsteroidManager& asteroidManager){
    float score;
    for (int i = asteroidManager.asteroids.size() - 1; i >= 0; i--)
    {
        for (int j = saucers.size() - 1; j >= 0; j--)        
        {
            if(CheckCollisionCircles(saucers[j].position, saucers[j].size, asteroidManager.asteroids[i].position, asteroidManager.asteroids[i].size)){
                
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,asteroidManager.asteroids[i].size);
                asteroidManager.AddAsteroid(asteroidManager.asteroids[i].position,asteroidManager.asteroids[i].size);  
                asteroidManager.asteroids.erase(asteroidManager.asteroids.begin() + i);
                saucers.erase(saucers.begin() + j);
                score += 1000;              
            }
        }
    }   
}

void SaucerManager::Update(){
    for (int i = 0; i < saucers.size(); i++)
    {
        saucers[i].Update();
    }
}

void SaucerManager::Draw(){
    for (int i = 0; i < saucers.size(); i++)
    {
        saucers[i].Draw();
    }

}

void SaucerManager::AddSaucer(Saucer saucer){
    saucers.push_back(saucer);
}