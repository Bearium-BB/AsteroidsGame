#include "GameMode.h"
#include "Player.h"
#include "Asteroid.h"
#include <iostream>
#include "Saucer.h"


GameMode::GameMode(){
    score = 0;
    player = new Player(&bulletManager);
    music = LoadMusicStream("MP3/MusicBackground.mp3");
    music.looping = true;
    PlayMusicStream(music);
}

void GameMode::Update(){
    UpdateMusicStream(music);
    
    float addToScore = 0;
    player->Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(*player); 

    bulletManager.Update();

    addToScore += bulletManager.BulletToAsteroidCollision(asteroidManager);
    bulletManager.SaucerBulletToPlayerCollision(player);

    saucerManager.SaucerToAsteroidCollision(asteroidManager);

    newLifeScore += addToScore;
    saucerScore += addToScore;
    score += addToScore;

    std::cout << score << std::endl;
    DrawText(TextFormat("Score: %02.02f", score), 25, 25, 20, BLUE);
    DrawText(TextFormat("Hp: %02.02f", player->health), 200, 25, 20, GREEN);

    if(newLifeScore == 10000){
        newLifeScore -= newLifeScore;
        player->health += 1;
    }

    if(saucerScore == 10000){
        saucerScore -= saucerScore;
        saucerManager.AddSaucer(Saucer(player, &bulletManager));
    }

    if(player->health == 0){
        player->health = 3;
        asteroidManager.GameOver();
    }

    saucerManager.Update();
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
    saucerManager.Draw();
}