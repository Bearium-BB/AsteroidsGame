#ifndef ACTOR_H
#define ACTOR_H

#include "raylib.h"
#include "PolygonCollision.h"
#include <vector>

class Actor {
public:
    Vector2 position;
    Vector2 velocity;

    virtual std::vector<Vector2> GetWorldVertices() const = 0;

    virtual ~Actor() = default;
};

#endif
