#include <stdio.h>
#include <SDL3/SDL.h>
#include "render.h"
#include "text.h"
#include <SDL3/SDL_ttf.h>

int main() {
    printf("Starting...\n");
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 1024;
    const int height = 1024;

    SDL_Window* window = SDL_CreateWindow("nomikop", 500, 500, SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        printf("%s\n", SDL_GetError());
    } else {
        SDL_Renderer* r = SDL_CreateRenderer(window, NULL, 0);
        if (r == NULL) {
            printf("%s\n", SDL_GetError());
        }

        SDL_SetRenderLogicalPresentation(r, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX, SDL_SCALEMODE_BEST);

        TTF_Font* font = initFont();
        SDL_Texture* textTexture = createTextTexture(font, r, "NOMIKOP!");

        const SDL_FRect textRect = {0, 0, 500, 250};

        int x = 0;
        int y = 0;

        const float pHeight = 40;
        const float pWidth = 25;
        SDL_FRect p = { width / 2 - pWidth / 2 , height / 2 - pHeight / 2, pWidth, pHeight };

        int running = 1;
        while (running) {
            clear(r);

            renderBackground(r, -x, -y);

            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
            SDL_RenderFillRect(r, &p);

            SDL_RenderTexture(r, textTexture, NULL, &textRect);

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_EVENT_QUIT:
                        running = 0;
                        break;

                    case SDL_EVENT_KEY_UP:
                        printf("key\n");
                        if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
                            printf("left\n");
                            x -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                            printf("right\n");
                            x += 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
                            printf("up\n");
                            y -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                            printf("down\n");
                            y += 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_C) {
                        }
                        break;
                }
            }
            SDL_RenderPresent(r);
            SDL_Delay(20);
        }

        SDL_DestroyTexture(textTexture);
        SDL_DestroyRenderer(r);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

