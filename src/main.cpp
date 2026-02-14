#include "raylib.h"
#include "rlgl.h"
#include <math.h>


class Player {
  public:
    Vector2 position = {0,0};

    Vector2 p1 = { 100, 50.0f };
    Vector2 p2 = { 100 - 20.0f, 100.0f };
    Vector2 p3 = { 100 + 20.0f, 100.0f };

    Vector2 center = {
        (p1.x + p2.x + p3.x) / 3.0f,
        (p1.y + p2.y + p3.y) / 3.0f
    };

    double angle = 0;

    
    void Update(){
        if (IsKeyDown(KEY_W))
        {
            float rad = (angle - 90.0f) * DEG2RAD;

            Vector2 forward = {
                cosf(rad),
                sinf(rad)
            };

            position.x += forward.x * 1;
            position.y += forward.y * 1;
        }

        if (IsKeyDown(KEY_D))
        {
            angle++;
        }
        if (IsKeyDown(KEY_A))
        {
            angle--;
        }

        if (angle >= 360) angle -= 360;
        if (angle <= 0) angle += 360;
    };

    void Draw(){
        rlPushMatrix();

            rlTranslatef(center.x + position.x, center.y + position.y, 0);

            rlRotatef(angle, 0, 0, 1);

            DrawTriangle(
                (Vector2){ p1.x - center.x, p1.y - center.y },
                (Vector2){ p2.x - center.x, p2.y - center.y },
                (Vector2){ p3.x - center.x, p3.y - center.y },
                VIOLET
            );

        rlPopMatrix();
    }
};

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    Player player;
        
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {     
   
        player.Update();
        BeginDrawing();
            ClearBackground(darkGreen);
            player.Draw();

        EndDrawing();
    }
    
    CloseWindow();
}
