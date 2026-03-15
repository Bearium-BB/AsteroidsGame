#include "raylib.h"
#include "Bullet.h"
#include "raymath.h"
#include "PolygonCollision.h"

Bullet::Bullet(float x, float y, double angle, std::string Tag)
{
    speed = 1000.0f;
    size  = 5.0f;
    timer = 5.0f;

    float rad = (float)((angle - 90.0) * DEG2RAD);
    Vector2 direction = { cosf(rad), sinf(rad) };

    position = { x, y };
    velocity = Vector2Scale(direction, speed);
    tag      = Tag;
}

std::vector<Vector2> Bullet::GetWorldVertices() const
{
    return BuildRegularPolygon(position, size, 4, 45.0f);
}

void Bullet::Update()
{
    dt       = GetFrameTime();
    position = Vector2Add(position, Vector2Scale(velocity, dt));
    Wrapping();
    timer -= dt;
}

void Bullet::Draw()
{
    auto verts = GetWorldVertices();
    int n = (int)verts.size();
    for (int i = 0; i < n; i++)
        DrawLineV(verts[i], verts[(i + 1) % n], { 255, 255, 255, 255 });
}

void Bullet::Wrapping()
{
    int w = GetScreenWidth();
    int h = GetScreenHeight();

    if (position.x >  w) position.x = 1.0f;
    if (position.x <  0) position.x = (float)(w - 1);
    if (position.y >  h) position.y = 1.0f;
    if (position.y <  0) position.y = (float)(h - 1);
}
