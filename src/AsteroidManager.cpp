#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"
#include <stdio.h>
#include <iostream>
#include "raymath.h"



AsteroidManager::AsteroidManager(){
    asteroids.resize(10);
}

void AsteroidManager::PlayerToAsteroidCollision(Player& player){
    for (int i = 0; i < asteroids.size(); i++)
    {
        if(CheckCollisionCircles(player.position,28,asteroids[i].position,asteroids[i].size)){
            player.TookDamage();
            std::cout << player.velocity.x << " , "
                    << player.velocity.y << " : " 
                    << Vector2Length(player.velocity) << std::endl;
            asteroids.erase(asteroids.begin() + i);
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