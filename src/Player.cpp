#include "Player.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "BulletManager.h"

Player::Player(BulletManager* bulletManagerTest)
{
    position = { (float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f };
    velocity = { 0, 0 };

    p1 = {  0.0f, -25.0f };
    p2 = { -20.0f,  25.0f };
    p3 = {  20.0f,  25.0f };



    center = {
        (p1.x + p2.x + p3.x) / 3.0f,
        (p1.y + p2.y + p3.y) / 3.0f
    };

    maxSpeed      = 7.0f;
    forwardSpeed  = 100.0f;
    rotationSpeed = 100.0f;
    dt            = GetFrameTime();
    health        = 3.0f;
    isInvincible  = false;
    elapsedTimeForIsInvincible = 0.0f;
    isInvincibleTime           = 2.0f;
    bulletManager = bulletManagerTest;
    color         = {255, 140, 0, 255};
}


void Player::Update()
{
    dt = GetFrameTime();
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    if (IsKeyDown(KEY_W))
    {
        float rad     = (float)((angle - 90.0) * DEG2RAD);
        Vector2 fwd   = Vector2Scale({ cosf(rad), sinf(rad) }, forwardSpeed * dt);
        velocity      = Vector2Add(velocity, fwd);
    }

    if (IsKeyDown(KEY_D)) angle += rotationSpeed * dt;
    if (IsKeyDown(KEY_A)) angle -= rotationSpeed * dt;

    if (IsKeyPressed(KEY_SPACE))
    {
        bulletManager->AddBullet(Bullet(position.x, position.y, angle, "player"));
        float rad   = (float)((angle + 90.0) * DEG2RAD);
        Vector2 fwd = Vector2Scale({ cosf(rad), sinf(rad) }, 10.0f * dt);
        velocity    = Vector2Add(velocity, fwd);
    }

    if (IsKeyPressed(KEY_Q))
    {
        position = { (float)GetRandomValue(0, w), (float)GetRandomValue(0, h) };
    }

    if (angle >= 360.0) angle -= 360.0;
    if (angle <    0.0) angle += 360.0;

    for (auto& b : bullets) b.Update();

    UpdatePosition();
    Wrapping();

    if (isInvincible)
    {
        elapsedTimeForIsInvincible += dt;
        if (elapsedTimeForIsInvincible > isInvincibleTime)
            isInvincible = false;
    }

    if (!isInvincible)
        color = { 255, 140, 0, 255 };
}

void Player::UpdatePosition()
{
    float spd = Vector2Length(velocity);
    if (spd > maxSpeed)
        velocity = Vector2Scale(Vector2Normalize(velocity), maxSpeed);

    position = Vector2Add(position, velocity);
    velocity = Vector2Scale(velocity, 0.95f);
}

void Player::Draw()
{
    rlPushMatrix();
        rlTranslatef(center.x + position.x, center.y + position.y, 0);
        rlRotatef((float)angle, 0, 0, 1);
        DrawTriangle(
            { p1.x - center.x, p1.y - center.y },
            { p2.x - center.x, p2.y - center.y },
            { p3.x - center.x, p3.y - center.y },
            color
        );
        
    rlPopMatrix();

    for (auto& b : bullets) b.Draw();
}

void Player::Wrapping()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    if (position.x >  w) position.x = 1.0f;
    if (position.x <  0) position.x = (float)(w - 1);
    if (position.y >  h) position.y = 1.0f;
    if (position.y <  0) position.y = (float)(h - 1);
}

void Player::TookDamage()
{
    if (!isInvincible)
    {
        position = { (float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f };
        elapsedTimeForIsInvincible = 0.0f;
        health--;
        isInvincible = true;
        color        = { 255, 0, 100, 255 };
        velocity     = { 0, 0 };
    }
}
