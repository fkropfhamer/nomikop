#include "screen.h"
#include "fight.h"
#include "world.h"


void changeScreen(const enum Screen screen) {
    switch (state.screen) {
        case FIGHT:
            unloadFightScreen();
        break;
        case WORLD:
            unloadWorldScreen();
            break;
    }

    state.screen = screen;
    switch (screen) {
        case FIGHT:
            loadFightScreen();
        break;
        case WORLD:
            loadWorldScreen();
            break;
    }
}
