#include "raylib.h"
#include "Bullet.h"
#include "raymath.h"


Bullet::Bullet(float x , float y, double angle){

    speed = 1000;
    size = 5;
    timer = 5; 

    float rad = (angle - 90.0f) * DEG2RAD;

    Vector2 direction = {cosf(rad), sinf(rad)};

    position = {x,y};

    velocity = Vector2Scale(direction,speed);

}

void Bullet::Update(){

    dt = GetFrameTime();

    position = Vector2Add(position,Vector2Scale(velocity,dt));
    Wrapping();
    timer -= dt;
}

void Bullet::Draw(){
    DrawCircle(position.x,position.y,size,{255,255,255,255});
}

void Bullet::Wrapping(){
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