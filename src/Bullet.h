#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "Actor.h"
#include "PolygonCollision.h"
#include <string>
#include <vector>

class Bullet : public Actor {
public:

    float speed;
    float size;
    float timer;
    float dt;
    std::string tag;

    Bullet(float x, float y, double angle, std::string Tag);

    void Update();
    void Draw();
    void Wrapping();

    // Returns a small diamond polygon in world space
    std::vector<Vector2> GetWorldVertices() const override;
};

#endif
