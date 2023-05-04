#include "Renderer.hpp"

Renderer::Renderer(SDL_Renderer *renderer) {
    this->renderer = renderer;
}

void Renderer::clear() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::present() {
    SDL_RenderPresent(renderer);
}

void Renderer::renderBackground(int offSetX, int offSetY) {
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            int x = offSetX + (i * 25);
            int y = offSetY + (j * 25);
            SDL_FRect p = { static_cast<float>(x), static_cast<float>(y), 25, 25 };

            if ((i + j) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            }

            SDL_RenderFillRect(renderer, &p);
        }
    }
}
