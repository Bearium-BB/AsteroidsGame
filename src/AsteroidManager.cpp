#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include <stdio.h>

AsteroidManager::AsteroidManager(){
    asteroids.resize(10);
}

void AsteroidManager::PlayerToAsteroidCollision(Player& player){
    for (int i = 0; i < asteroids.size(); i++)
    {
        if(CheckCollisionCircles(player.position,30,asteroids[i].position,asteroids[i].size)){
            player.TookDamage();
            printf("hit\n");
        }
    }    
}

void AsteroidManager::Update(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Update();
    }

}

void AsteroidManager::Draw(){
    for (int i = 0; i < asteroids.size(); i++)
    {
        asteroids[i].Draw();
    }

}