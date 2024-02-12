#include "fight.h"
#include "raylib.h"
#include "texture.h"
#include "screen.h"
#include "state.h"

static Texture2D texture1;
static Texture2D texture2;


void loadFightScreen() {
    texture1 = loadTexture("assets/textures/path1.png");
    texture2 = loadTexture("assets/textures/path1.png");
}

void unloadFightScreen() {
    UnloadTexture(texture1);
    UnloadTexture(texture2);
}

void updateFightScreen() {
    if (IsKeyPressed(KEY_X)) changeScreen(WORLD);
}

void drawFightScreen() {
    DrawTexture(texture1, 0, 0, WHITE);
    DrawTexture(texture2, 500, 200, WHITE);

    DrawText("FIGHT!", 190, 200, 20, LIGHTGRAY);
}
