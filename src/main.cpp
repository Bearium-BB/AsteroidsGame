#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include <stdio.h>
#include "Player.h"
#include "Asteroid.h"


int main() 
{
    const Color darkGreen = {20, 160, 133, 255};

    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;
        
    InitWindow(screenWidth, screenHeight, "My first RAYLIB program!");
    SetTargetFPS(60);


    Player player;
    Asteroid asteroids[10];


    while (!WindowShouldClose())
    {     
        player.Update();
        for (int i = 0; i < sizeof(asteroids) / sizeof(asteroids[0]); i++)
        {
            asteroids[i].Update();
        }

        for (int i = 0; i < sizeof(asteroids) / sizeof(asteroids[0]); i++)
        {
            if(CheckCollisionCircles(player.position,30,asteroids[i].position,asteroids[i].size)){
                printf("hit\n");
            }
        }
        
        
        BeginDrawing();
            ClearBackground(darkGreen);
            player.Draw();
            for (int i = 0; i < sizeof(asteroids) / sizeof(asteroids[0]); i++)
            {
                asteroids[i].Draw();
            } 
        EndDrawing();
    }
    
    CloseWindow();
}
