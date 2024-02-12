#include "render.h"

void clear(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void renderBackground(SDL_Renderer *renderer, int offSetX, int offSetY) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            int x = offSetX + (i * 25);
            int y = offSetY + (j * 25);
            SDL_FRect p = { x, y, 25, 25 };

            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            }

            SDL_RenderFillRect(renderer, &p);
        }
    }
}