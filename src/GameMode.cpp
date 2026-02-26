#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include <iostream>


GameMode::GameMode(){

    player = new Player(&bulletManager);
}

void GameMode::Update(){
    player->Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(*player); 
    bulletManager.Update();
    score += bulletManager.BulletToAsteroidCollision(asteroidManager);
    std::cout << score;
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
}