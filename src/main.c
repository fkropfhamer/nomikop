#include "fight.h"
#include "raylib.h"
#include "state.h"
#include "world.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------

screenWidth = 800;
screenHeight = 450;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Main Entry Point
//----------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "nomikop");

    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    loadState();

    loadWorldScreen();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    switch (state.screen) {
        case WORLD:
            updateWorldScreen();
        break;
        case FIGHT:
            updateFightScreen();
        break;
    }


    BeginDrawing();
    ClearBackground(RAYWHITE);


    switch (state.screen) {
        case WORLD:
            drawWorldScreen();
        break;
        case FIGHT:
            drawFightScreen();
        break;
    }

    EndDrawing();
}