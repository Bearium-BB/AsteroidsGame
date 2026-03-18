#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Player.h"
#include "Asteroid.h"
#include "GameMode.h"
#include "button.hpp"

int main() 
{
    const Color darkGreen = {0, 105, 110, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
    bool startGame = 0;
    
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    InitAudioDevice();
    SetTargetFPS(60);


    Button startButton({300, 200}, {200, 60}, "Start Game");    

    GameMode gameMode;

    while (!WindowShouldClose())
    {    
        if(startButton.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
            startGame = true;
        }


        if(startGame)
        {
            gameMode.Update();
        }
        else
        {
            const char* title = "Against The Curve";
            int fontSize = 20;

            int textWidth = MeasureText(title, fontSize);

            DrawText(title, screenWidth/2 - textWidth/2, 25, fontSize, BLACK);        
        }
 
        BeginDrawing();
            ClearBackground(darkGreen);
            if(startGame){
                gameMode.Draw();
            }
            else
            {
                startButton.Draw();
            }

        EndDrawing();
    }
    
    CloseWindow();
}
