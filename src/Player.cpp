#include "Player.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"


Player::Player()
{
    position = {(float)GetScreenWidth()/2,(float)GetScreenHeight()/2};
    velocity = {0,0};

    p1 = { 0.0f, -25.0f };
    p2 = { -20.0f, 25.0f };
    p3 = { 20.0f, 25.0f };

    center = {
        (p1.x + p2.x + p3.x) / 3.0f,
        (p1.y + p2.y + p3.y) / 3.0f
    };

    maxSpeed = 7;
    forwardSpeed = 100;
    rotationSpeed = 100;

    dt = GetFrameTime();

    health = 3;
    isInvincible = false;
    elapsedTimeForIsInvincible = 0;
    isInvincibleTime = 2;
}

void Player::Update(){
    dt = GetFrameTime();
    int current_width = GetScreenWidth();
    int current_height = GetScreenHeight();

    if (IsKeyDown(KEY_W))
    {
        float rad = (angle - 90.0f) * DEG2RAD;

        Vector2 forward = {
            cosf(rad),
            sinf(rad)
        };

        forward = Vector2Scale(forward,forwardSpeed * dt);
        velocity = Vector2Add(velocity,forward);
    }

    if (IsKeyDown(KEY_D))
    {
        angle += rotationSpeed * dt;
    }

    if (IsKeyDown(KEY_A))
    {
        angle -= rotationSpeed * dt;
    }

    if (IsKeyPressed(KEY_SPACE))
    {
        bullets.push_back(Bullet(position.x,position.y,angle));
    }

    if (IsKeyPressed(KEY_Q))
    {
        float x = GetRandomValue(0, current_width); 
        float y = GetRandomValue(0, current_height); 
        position = {x,y};
    }

    if (angle >= 360) angle -= 360;
    if (angle <= 0) angle += 360;


    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Update();
    }

    UpdatePosition();
    Wrapping();

    for (int i = 0; i < bullets.size(); i++)
    {
        if(bullets[i].timer < 0){
            bullets.erase(bullets.begin() + i);
        }
    }
    
    if(isInvincible){
        elapsedTimeForIsInvincible += dt;
    }

    if(elapsedTimeForIsInvincible > isInvincibleTime){
        isInvincible = false;
    }
};

void Player::UpdatePosition() {
    float currentSpeed = Vector2Length(velocity);

    if (currentSpeed > maxSpeed) {
        velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);
    }

    position = Vector2Add(position, velocity);

    velocity = Vector2Scale(velocity, 0.95f);
}

void Player::Draw(){
    rlPushMatrix();

        rlTranslatef(center.x + position.x, center.y + position.y, 0);

        rlRotatef(angle, 0, 0, 1);

        DrawTriangle(
            (Vector2){ p1.x - center.x, p1.y - center.y },
            (Vector2){ p2.x - center.x, p2.y - center.y },
            (Vector2){ p3.x - center.x, p3.y - center.y },
            VIOLET
        );

    rlPopMatrix();
    for (int i = 0; i < bullets.size(); i++)
    {
        bullets[i].Draw();
    }
}

void Player::Wrapping(){
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

void Player::TookDamage(){
    if(!isInvincible){
        position = {(float)GetScreenWidth()/2,(float)GetScreenHeight()/2};
        elapsedTimeForIsInvincible = 0;
        health--;
        isInvincible = true;
    }
}
