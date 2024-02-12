#include "raylib.h"
#include "texture.h"
#include "state.h"

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
int screenWidth = 800;
int screenHeight = 450;

struct State state;

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame


void drawWorld(const Texture2D texture) {
    DrawTexture(texture, screenWidth/2 - texture.width/2 + state.pos.x, screenHeight/2 - texture.height/2 + state.pos.y, WHITE);

    DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
}

void changeScreen(const enum Screen screen) {
    state.screen = screen;
}

void checkInputWorld(void) {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) state.pos.x += 2.0f;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) state.pos.x -= 2.0f;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) state.pos.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) state.pos.y += 2.0f;
    if (IsKeyPressed(KEY_F)) changeScreen(state.screen == WORLD ? FIGHT : WORLD);
}

void drawFight(void) {
    DrawText("FIGHT!", 190, 200, 20, LIGHTGRAY);
}

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

    loadState(&state);

    const Texture2D texture = loadTexture("assets/textures/path1.png");
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        checkInputWorld();


        BeginDrawing();
            ClearBackground(RAYWHITE);


            switch (state.screen) {
                case WORLD:
                    drawWorld(texture);
                    break;
                case FIGHT:
                    drawFight();
                    break;
            }

        EndDrawing();
        // UpdateDrawFrame();
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
    // Update
    //----------------------------------------------------------------------------------
    // TODO: Update your variables here
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
    //----------------------------------------------------------------------------------
}