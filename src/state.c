#include "state.h"

void loadState(struct State* state) {
    state->pos.x = 0;
    state->pos.y = 0;

    state->screen = WORLD;
}

void safeState(struct State* state) {

}
