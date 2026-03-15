#ifndef ASTEROID_H
#define ASTEROID_H

#include "raylib.h"
#include "Actor.h"
#include "PolygonCollision.h"
#include <vector>

class Asteroid : public Actor {
public:

    Vector2 direction;

    float maxSpeed;
    float dt;
    float speed;
    float size;
    float angle;    

    std::vector<float> radiusOffsets;
    int numSides;

    Asteroid();
    Asteroid(Vector2 position, float parentSize);

    void Update();
    void Draw();
    void Wrapping();

    std::vector<Vector2> GetWorldVertices() const override;
};

#endif
