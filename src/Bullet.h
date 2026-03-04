#ifndef BULLET_H
#define BULLET_H

#include "raylib.h"
#include "Actor.h"
#include <string>

class Bullet : public Actor {
public:

    float speed;
    float size;
    float timer;
    float dt;
    std::string tag; 

    Bullet(float x , float y, double angle, std::string  Tag);

    void Update();
    void Draw();
    void Wrapping();      
};

#endif
