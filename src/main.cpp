#include <iostream>
#include "SDL3/SDL.h"
#include "SDL3/SDL_ttf.h"
#include "Renderer.hpp"

int main() {
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 1920;
    const int height = 1080;

    auto window = SDL_CreateWindow("nomikop", 500, 500, SDL_WINDOW_RESIZABLE);

    if (window == nullptr) {
        std::cout << SDL_GetError() << "\n";
    } else {
        auto r = SDL_CreateRenderer(window, nullptr, 0);
        if (r == nullptr) {
            std::cout << SDL_GetError() << "\n";
        }
        
        SDL_SetRenderLogicalPresentation(r, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX, SDL_SCALEMODE_BEST);

        if (TTF_Init() == -1) {
            std::cout << TTF_GetError()  << "\n";
        }

        auto font = TTF_OpenFont("./assets/FiraSans-Black.ttf", 256);
        if (font == nullptr) {
            std::cout << TTF_GetError() << "\n"; 
        }

        SDL_Color white = {255, 255, 255};
        auto textSurface = TTF_RenderUTF8_Solid(font, "NOMIKOP!", white);
        auto textTexture = SDL_CreateTextureFromSurface(r, textSurface);
        SDL_DestroySurface(textSurface);

        SDL_FRect textRect = {0, 0, 500, 250};

        int x = 0;
        int y = 0;

        float pHeight = 40;
        float pWidth = 25;
        SDL_FRect p = { width / 2 - pWidth / 2 , height / 2 - pHeight / 2, pWidth, pHeight };

        auto renderer = Renderer(r);

        auto running = true;
        auto displayText = false;
        while (running) {
            renderer.clear();

            renderer.renderBackground(-x, -y);

            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
            SDL_RenderFillRect(r, &p);

            if (displayText) {
                SDL_RenderTexture(r, textTexture, nullptr, &textRect);
            }
            

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
                            displayText = !displayText;
                        }
                        break;
                }
            }
            renderer.present();
            SDL_Delay(20);
        }

        SDL_DestroyTexture(textTexture);
        SDL_DestroyRenderer(r);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

