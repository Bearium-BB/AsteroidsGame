#include "button.hpp"

Button::Button(Vector2 pos, Vector2 size, const char* text)
{
    position = pos;
    this->size = size;
    label = text;

    rect = { position.x, position.y, size.x, size.y };
}

void Button::Draw()
{
    DrawRectangleRec(rect, LIGHTGRAY);

    DrawRectangleLinesEx(rect, 2, BLACK);

    int fontSize = 20;

    int textWidth = MeasureText(label, fontSize);

    float textX = position.x + (size.x / 2) - (textWidth / 2);
    float textY = position.y + (size.y / 2) - (fontSize / 2);

    DrawText(label, textX, textY, fontSize, BLACK);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed)
{
    if (CheckCollisionPointRec(mousePos, rect) && mousePressed)
    {
        return true;
    }

    return false;
}