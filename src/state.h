#ifndef STATE_H
#define STATE_H

#include "raylib.h"

extern int screenWidth;
extern int screenHeight;

enum Screen {
    FIGHT,
    WORLD,
};

struct State {
    Vector2 pos;
    enum Screen screen;
};

struct State state;

void loadState();
void safeState();

#endif //STATE_H
