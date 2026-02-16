#include <vector>
#include "raylib.h"
#include "Asteroid.h"
#include "AsteroidManager.h"
#include "Player.h"

void AsteroidManager::PlayerToAsteroidCollision(Player player){
    for (int i = 0; i < asteroids.size(); i++)
    {
        if(CheckCollisionCircles(player.position,30,asteroids[i].position,asteroids[i].size)){
        }
    }    
}