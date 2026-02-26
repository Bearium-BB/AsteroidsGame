#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Player.h"
#include "Asteroid.h"
#include "GameMode.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
        
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    InitAudioDevice();
    SetTargetFPS(60);

    GameMode gameMode;

    while (!WindowShouldClose())
    {     
        gameMode.Update();
 
        BeginDrawing();
            ClearBackground(darkGreen);
            gameMode.Draw();

        EndDrawing();
    }
    
    CloseWindow();
}
