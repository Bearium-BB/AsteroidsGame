#include "Asteroid.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Saucer.h"
#include "Player.h"
#include "BulletManager.h"
#include "PolygonCollision.h"
#include <iostream>

static void InitSaucer(Saucer& s, float sz)
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();
    float py = (float)GetRandomValue(0, h);

    s.size     = sz;
    s.velocity = { -50.0f, 0.0f };
    s.position = { (float)w, py };
}

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest)
{
    player        = currentPlayer;
    bulletManager = bulletManagerTest;
    InitSaucer(*this, (float)GetRandomValue((int)minSize, (int)maxSize));
}

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim)
{
    player              = currentPlayer;
    bulletManager       = bulletManagerTest;
    smallSaucerImproveAim = improvedAim;
    InitSaucer(*this, (float)GetRandomValue((int)minSize, (int)maxSize));
}

Saucer::Saucer(Player* currentPlayer, BulletManager* bulletManagerTest, bool improvedAim, float sizeSaucer)
{
    player              = currentPlayer;
    bulletManager       = bulletManagerTest;
    smallSaucerImproveAim = improvedAim;
    InitSaucer(*this, sizeSaucer);
}

Saucer::Saucer() {}

std::vector<Vector2> Saucer::GetWorldVertices() const
{
    return BuildRegularPolygon(position, size, 6, 0.0f);
}

void Saucer::Update()
{
    dt = GetFrameTime();
    timeToShoot -= dt;

    position = Vector2Add(position, Vector2Scale(velocity, dt));
    Wrapping();

    if (timeToShoot < 0.0f)
    {
        if (!smallSaucerImproveAim && size > 30.0f)
        {
            float normalizedSize  = (size - minSize) / (maxSize - minSize);
            float randomOffset    = (float)GetRandomValue((int)(normalizedSize * -100), (int)(normalizedSize * 100));

            Vector2 dir    = Vector2Subtract(player->position, position);
            float   angle  = atan2f(dir.y, dir.x) * RAD2DEG;
            float   finalAngle = angle + randomOffset;

            bulletManager->AddBullet(Bullet(position.x, position.y, finalAngle + 90.0f, "saucer"));
        }
        else
        {
            float normalizedSize = (size - minSize) / (maxSize - minSize);
            float randomOffset   = (float)GetRandomValue((int)(normalizedSize * -40), (int)(normalizedSize * 40));

            Vector2 dir   = Vector2Subtract(player->position, position);
            float   angle = atan2f(dir.y, dir.x) * RAD2DEG;
            float   finalAngle = angle + randomOffset;

            bulletManager->AddBullet(Bullet(position.x, position.y, finalAngle + 90.0f, "saucer"));
        }

        timeToShoot = 3.0f;
    }
}

void Saucer::Draw()
{
    auto verts = GetWorldVertices();
    int n = (int)verts.size();
    for (int i = 0; i < n; i++)
        DrawLineEx(verts[i], verts[(i + 1) % n], 2.0f, { 100, 100, 255, 255 });
}

void Saucer::Wrapping()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    if (position.x >  w) position.x = 1.0f;
    if (position.x <  0) position.x = (float)(w - 1);
    if (position.y >  h) position.y = 1.0f;
    if (position.y <  0) position.y = (float)(h - 1);
}
