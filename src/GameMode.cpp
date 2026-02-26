#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include <iostream>


GameMode::GameMode(){
    score = 0;
    player = new Player(&bulletManager);
}

void GameMode::Update(){
    player->Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(*player); 
    bulletManager.Update();
    score += bulletManager.BulletToAsteroidCollision(asteroidManager);
    std::cout << score << std::endl;
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
}