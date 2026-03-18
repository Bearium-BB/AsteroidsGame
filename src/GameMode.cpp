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
    smallSaucerTimer = 10;
    nextAsteroid = 5;
    saucerManager = SaucerManager();
    currentLevel = 0;
    NextLevel();
}

void GameMode::Update(){
    dt = GetFrameTime();

    UpdateMusicStream(music);

    smallSaucerTimer -= dt;

    float addToScore = 0;

    player->Update();
    asteroidManager.Update();
    asteroidManager.PlayerToAsteroidCollision(*player); 

    bulletManager.Update();

    addToScore += bulletManager.BulletToAsteroidCollision(asteroidManager);
    bulletManager.SaucerBulletToPlayerCollision(player);
    bulletManager.PlayerBulletToSaucerCollision(saucerManager);

    saucerManager.SaucerToAsteroidCollision(asteroidManager);

    newLifeScore += addToScore;
    saucerScore += addToScore;
    score += addToScore;

    //std::cout << score << std::endl;
    DrawText(TextFormat("Score: %02.02f", score), 25, 25, 20, {255,255,255,255});
    DrawText(TextFormat("Hp: %02.02f", player->health), 200, 25, 20, {255,255,255,255});
    DrawText(TextFormat("Level %d", currentLevel), 375, 25, 20, {255,255,255,255});

    if(newLifeScore == 10000){
        newLifeScore -= newLifeScore;
        player->health += 1;
    }

    if(saucerScore == 10000){
        saucerScore -= saucerScore;
        if(saucerScore < 10000){
            saucerManager.AddSaucer(Saucer(player, &bulletManager));
        }else{
            saucerManager.AddSaucer(Saucer(player, &bulletManager,true));
        }
    }

    if(player->health == 0){
        player->health = 3;
        score = 0;
        nextAsteroid = 5;
        currentLevel = 1;
        asteroidManager.GameOver();
        asteroidManager.asteroids.clear();
        asteroidManager.asteroids.resize(nextAsteroid);
        score = 0;
    }

    if(smallSaucerTimer < 0){
        if(saucerScore < 10000){
            saucerManager.AddSaucer(Saucer(player, &bulletManager,false,25));
        }else{
            saucerManager.AddSaucer(Saucer(player, &bulletManager,true,25));
        }
        smallSaucerTimer = 10;
    }

    saucerManager.Update();

    if(saucerManager.saucers.size() == 0 && asteroidManager.asteroids.size() == 0){
        NextLevel();
    }
}

void GameMode::Draw(){
    player->Draw();
    asteroidManager.Draw();
    bulletManager.Draw();
    saucerManager.Draw();
}

void GameMode::NextLevel(){
    bulletManager.bullets.clear();
    saucerManager.saucers.clear();
    asteroidManager.asteroids.clear();
    asteroidManager.asteroids.resize(nextAsteroid);
    nextAsteroid += 2;
    currentLevel++;
    score = 0;
}
