#include <iostream>
#include "SDL3/SDL.h"
#include "Renderer.hpp"

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 500;
    const int height = 500;

    auto window = SDL_CreateWindow("nomikop", width, height, 0);

    if (window == nullptr) {
        std::cout << SDL_GetError() << "\n";
    } else {
        auto r = SDL_CreateRenderer(window, nullptr, 0);
        if (r == nullptr) {
            std::cout << SDL_GetError() << "\n";
        }

        int x = 0;
        int y = 0;

        float pHeight = 40;
        float pWidth = 25;
        SDL_FRect p = { width / 2 - pWidth / 2 , height / 2 - pHeight / 2, pWidth, pHeight };

        auto renderer = Renderer(r);

        auto running = true;
        while (running) {
            renderer.clear();

            renderer.renderBackground(-x, -y);

            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
            SDL_RenderFillRect(r, &p);

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_EVENT_QUIT:
                        running = false;
                        break;

                    case SDL_EVENT_KEY_UP:
                        if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                            std::cout << "left\n";
                            x -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                            std::cout << "right\n";
                            x += 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
                            std::cout << "up\n";
                            y -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                            y += 5;
                            std::cout << "down\n";
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_C) {
                        }
                        break;
                }
            }
            renderer.present();
            SDL_Delay(20);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

