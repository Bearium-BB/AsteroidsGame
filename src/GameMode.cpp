#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"

GameMode::GameMode(){

}

void GameMode::Update(){
    player.Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(player);
}


void GameMode::Draw(){
    player.Draw();
    asteroidManager.Draw();
}