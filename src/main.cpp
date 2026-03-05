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
    bool startGame = 0;
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    InitAudioDevice();
    SetTargetFPS(60);

    GameMode gameMode;

    while (!WindowShouldClose())
    {    
        if(IsKeyDown(KEY_SPACE))
        {
            startGame = 1;
        } 

        if(startGame)
        {
            gameMode.Update();
        }
        else
        {
            DrawText("Asteroids Game", screenWidth/2, 25, 20, BLACK);
            DrawText("Press Space To Play", screenWidth/2, 100, 20, BLACK);
        }
 
        BeginDrawing();
            ClearBackground(darkGreen);
            if(startGame){
                gameMode.Draw();
            }
            else
            {
                    Rectangle sourceRec = { 0, 0, 100, 100 };
            }

        EndDrawing();
    }
    
    CloseWindow();
}
