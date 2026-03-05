#include "Asteroid.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Saucer.h"
#include "Player.h"
#include "BulletManager.h"
#include <iostream>

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest)
{
    player = currentPlayer;
    bulletManager = bulletManagerTest;
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    float py = GetRandomValue(0, current_height); 

    size = GetRandomValue(minSize,maxSize);
    velocity = {-50,0};
    position = {(float)current_width,py};

}

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest,bool improvedAim)
{
    player = currentPlayer;
    bulletManager = bulletManagerTest;
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    float py = GetRandomValue(0, current_height); 

    size = GetRandomValue(minSize,maxSize);
    velocity = {-50,0};
    position = {(float)current_width,py};

    smallSaucerImproveAim = improvedAim;

}

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest,bool improvedAim, float sizeSaucer)
{
    player = currentPlayer;
    bulletManager = bulletManagerTest;
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    float py = GetRandomValue(0, current_height); 

    size = sizeSaucer;
    velocity = {-50,0};
    position = {(float)current_width,py};

    smallSaucerImproveAim = improvedAim;

}

Saucer::Saucer(){

}

void Saucer::Update()
{
    dt = GetFrameTime();

    timeToShoot -= dt;

    position = Vector2Add(position,Vector2Scale(velocity,dt));
    Wrapping();

    if(timeToShoot < 0){
        if(!smallSaucerImproveAim && size > 30)
        {
            float normalizedSize = (size - minSize) / (maxSize - minSize);

            float randomOffset = GetRandomValue(normalizedSize * -100 , normalizedSize * 100);

            std::cout << randomOffset << std::endl;

            Vector2 dir = Vector2Subtract(player->position, position);

            float angle = atan2f(dir.y, dir.x) * RAD2DEG;

            float finalAngle = angle + randomOffset;

            Vector2Add(player->position,velocity);

            std::cout << angle << std::endl;

            std::cout << finalAngle << std::endl;

            bulletManager->AddBullet(Bullet(position.x,position.y,finalAngle + 90, "saucer"));
        }
        else
        {
            float normalizedSize = (size - minSize) / (maxSize - minSize);

            float randomOffset = GetRandomValue(normalizedSize * -40 , normalizedSize * 40);

            std::cout << randomOffset << std::endl;

            Vector2 dir = Vector2Subtract(player->position, position);

            float angle = atan2f(dir.y, dir.x) * RAD2DEG;

            float finalAngle = angle + randomOffset;

            float distance = Vector2Length(dir);

            float timeToHit = distance / 100;

            Vector2Add(player->position,Vector2Scale(player->velocity, timeToHit));

            std::cout << angle << std::endl;

            std::cout << finalAngle << std::endl;

            bulletManager->AddBullet(Bullet(position.x,position.y,finalAngle + 90, "saucer"));
        }

        timeToShoot = 3;
    }
}

void Saucer::Draw(){
    DrawCircle(position.x,position.y,size,{0,0,50,255});
}

void Saucer::Wrapping(){
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    if(position.x > current_width){
        position.x = 1;
    }

    if(position.x < 0){
    position.x = current_width - 1;
    }

    if(position.y > current_height){
        position.y = 1;
    }

    if(position.y < 0){
        position.y = current_height - 1;
    }
}