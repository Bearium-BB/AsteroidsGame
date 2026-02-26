#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include <iostream>


GameMode::GameMode(){
    score = 0;
    player = new Player(&bulletManager);
    music = LoadMusicStream("background_music.ogg");
    music.looping = true;
    PlayMusicStream(music);
}

void GameMode::Update(){
    float addToScore = 0;
    player->Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(*player); 
    bulletManager.Update();

    addToScore += bulletManager.BulletToAsteroidCollision(asteroidManager);
    newLifeScore += addToScore;
    score += addToScore;

    std::cout << score << std::endl;
    DrawText(TextFormat("Score: %02.02f", score), 25, 25, 20, BLUE);
    DrawText(TextFormat("Hp: %02.02f", player->health), 200, 25, 20, GREEN);

    if(newLifeScore == 10000){
        newLifeScore -= newLifeScore;
        player->health += 1;
    }

    if(player->health == 0){

    }
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
}