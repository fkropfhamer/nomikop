#ifndef STATE_H
#define STATE_H

#include "raylib.h"

enum Screen {
    FIGHT,
    WORLD,
};

struct State {
    Vector2 pos;
    enum Screen screen;
};

void loadState(struct State* state);
void safeState(struct State* state);

#endif //STATE_H
