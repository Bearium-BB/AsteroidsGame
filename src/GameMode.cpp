#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include <iostream>
#include "Saucer.h"


GameMode::GameMode(){
    score = 0;
    player = new Player(&bulletManager);
    music = LoadMusicStream("../MP3/MusicBackground.mp3");
    music.looping = true;
    PlayMusicStream(music);
    testSaucer = Saucer(player, &bulletManager);
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
        player->health = 3;
        asteroidManager.GameOver();
    }
    testSaucer.Update();
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
    testSaucer.Draw();
}