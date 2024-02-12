#include "world.h"

#include "raylib.h"
#include "screen.h"
#include "state.h"
#include "texture.h"


static Texture2D texture;

void checkInputWorld(void) {
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) state.pos.x += 2.0f;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) state.pos.x -= 2.0f;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) state.pos.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) state.pos.y += 2.0f;
    if (IsKeyPressed(KEY_F)) changeScreen(FIGHT);
}

void loadWorldScreen() {
    texture = loadTexture("assets/textures/path1.png");
}

void unloadWorldScreen() {
    UnloadTexture(texture);
}

void updateWorldScreen() {
    checkInputWorld();
}

void drawWorldScreen() {
    DrawTexture(texture, screenWidth/2 - texture.width/2 + state.pos.x, screenHeight/2 - texture.height/2 + state.pos.y, WHITE);

    DrawText("World", 190, 200, 20, LIGHTGRAY);
}


