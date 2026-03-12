#pragma once
#include "raylib.h"

class Button
{
public:
    Button(Vector2 pos, Vector2 size, const char* text);

    void Draw();
    bool isPressed(Vector2 mousePos, bool mousePressed);

private:
    Vector2 position;
    Vector2 size;
    const char* label;

    Rectangle rect;
};