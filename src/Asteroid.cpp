#include "Asteroid.h"
#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "PolygonCollision.h"

static void InitAsteroid(Asteroid& a, float sz)
{
    a.size    = sz;
    a.speed   = 300.0f / (sz / 2.0f);
    a.angle   = (float)GetRandomValue(0, 359);
    a.numSides = GetRandomValue(6, 10);

    a.radiusOffsets.resize(a.numSides);
    for (int i = 0; i < a.numSides; i++)
        a.radiusOffsets[i] = (float)GetRandomValue(-30, 30) / 100.0f * sz;
}

Asteroid::Asteroid()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    position  = { (float)GetRandomValue(0, w), (float)GetRandomValue(0, h) };
    float dirX = (float)GetRandomValue(-1000, 1000) / 1000.0f;
    float dirY = (float)GetRandomValue(-1000, 1000) / 1000.0f;
    direction  = { dirX, dirY };

    InitAsteroid(*this, (float)GetRandomValue(15, 40));
    velocity = Vector2Scale(direction, speed);
}

Asteroid::Asteroid(Vector2 pos, float parentSize)
{
    float dirX = (float)GetRandomValue(-1000, 1000) / 1000.0f;
    float dirY = (float)GetRandomValue(-1000, 1000) / 1000.0f;
    direction  = { dirX, dirY };
    position   = pos;

    InitAsteroid(*this, parentSize / 2.0f);
    velocity = Vector2Scale(direction, speed);
}

std::vector<Vector2> Asteroid::GetWorldVertices() const
{
    std::vector<Vector2> verts;
    verts.reserve(numSides);
    float step = 360.0f / numSides;
    for (int i = 0; i < numSides; i++)
    {
        float rad    = (angle + step * i) * DEG2RAD;
        float r      = size + radiusOffsets[i];
        verts.push_back({ position.x + cosf(rad) * r,
                          position.y + sinf(rad) * r });
    }
    return verts;
}

void Asteroid::Update()
{
    dt = GetFrameTime();
    position = Vector2Add(position, Vector2Scale(velocity, dt));
    angle   += 20.0f * dt;         
    if (angle >= 360.0f) angle -= 360.0f;
    Wrapping();
}

void Asteroid::Draw()
{
    auto verts = GetWorldVertices();
    int n = (int)verts.size();
    for (int i = 0; i < n; i++)
    {
        Vector2 a = verts[i];
        Vector2 b = verts[(i + 1) % n];
        DrawLineEx(a, b, 2.0f, { 0, 200, 200, 255 });
    }
}

void Asteroid::Wrapping()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    if (position.x >  w) position.x = 1.0f;
    if (position.x <  0) position.x = (float)(w - 1);
    if (position.y >  h) position.y = 1.0f;
    if (position.y <  0) position.y = (float)(h - 1);
}
