#include "raylib.h"
#include "rlgl.h"
#include <math.h>
#include "raymath.h"
#include "Player.h"
#include "Asteroid.h"
#include "GameMode.h"
#include "button.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

namespace
{
    const Color darkGreen = {0, 105, 110, 255};
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 600;

    bool startGame = false;
    Button* startButton = nullptr;
    GameMode* gameMode = nullptr;

    void UpdateDrawFrame()
    {
        if(startButton->isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        {
            startGame = true;
            // Created on click so audio starts after a user gesture (required by browsers)
            gameMode = new GameMode();
        }

        if(startGame)
        {
            gameMode->Update();
        }

        BeginDrawing();
            ClearBackground(darkGreen);
            if(startGame)
            {
                gameMode->Draw();
            }
            else
            {
                const char* title = "Against The Curve";
                int fontSize = 20;
                int textWidth = MeasureText(title, fontSize);
                DrawText(title, screenWidth/2 - textWidth/2, 25, fontSize, BLACK);

                startButton->Draw();
            }
        EndDrawing();
    }
}

int main()
{
    InitWindow(screenWidth, screenHeight, "Against The Curve");
    InitAudioDevice();

    startButton = new Button({300, 200}, {200, 60}, "Start Game");

#if defined(PLATFORM_WEB)
    // The browser owns the loop; 0 = use requestAnimationFrame, 1 = simulate infinite loop
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        UpdateDrawFrame();
    }
#endif

    delete gameMode;
    delete startButton;
    CloseAudioDevice();
    CloseWindow();
    return 0;
}
