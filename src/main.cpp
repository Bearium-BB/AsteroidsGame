#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Player.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
        
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);


    Player player;


    while (!WindowShouldClose())
    {     
   
        player.Update();
        BeginDrawing();
            ClearBackground(darkGreen);
            player.Draw();
            DrawCircle(0, 0, 50.0f, MAROON);                
        EndDrawing();
    }
    
    CloseWindow();
}
