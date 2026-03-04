#include "Asteroid.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Saucer.h"
#include "Player.h"
#include "BulletManager.h"

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest)
{
    player = currentPlayer;
    bulletManager = bulletManagerTest;
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    float py = GetRandomValue(0, current_height); 

    size = 30;
    velocity = {-50,0};
    position = {(float)current_width,py};

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
        Vector2 dir = Vector2Subtract(player->position, position);

        float angle = atan2f(dir.y, dir.x) * RAD2DEG;
        Vector2Add(player->position,velocity);

        bulletManager->AddBullet(Bullet(position.x,position.y,angle + 90, "saucer"));
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