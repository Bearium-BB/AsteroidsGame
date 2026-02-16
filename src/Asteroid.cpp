#include "Asteroid.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"

Asteroid::Asteroid(){

    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    float px = GetRandomValue(0, current_width); 
    float py = GetRandomValue(0, current_height); 

    float directionX = (float)GetRandomValue(-1000, 1000)/1000;
    float directionY = (float)GetRandomValue(-1000, 1000)/1000;
    
    speed = 100;

    position = {px,py};
    direction = {directionX,directionY};
    velocity = Vector2Scale(direction,speed);

    size = GetRandomValue(5, 20);
}

void Asteroid::Update(){

    dt = GetFrameTime();

    position = Vector2Add(position,Vector2Scale(velocity,dt));
    Wrapping();
}

void Asteroid::Draw(){
    DrawCircle(position.x,position.y,size,{0,120,120,255});
}

void Asteroid::Wrapping(){
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