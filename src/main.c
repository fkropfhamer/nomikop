#include <stdio.h>
#include "SDL3/SDL.h"
#include "render.h"

int main() {
    printf("Starting...");
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 500;
    const int height = 500;

    SDL_Window* window = SDL_CreateWindow("nomikop", width, height, 0);

    if (window == NULL) {
        printf("%s", SDL_GetError());
    } else {
        SDL_Renderer* r = SDL_CreateRenderer(window, NULL, 0);
        if (r == NULL) {
            printf("%s", SDL_GetError());
        }

        int x = 0;
        int y = 0;

        float pHeight = 40;
        float pWidth = 25;
        SDL_FRect p = { width / 2 - pWidth / 2 , height / 2 - pHeight / 2, pWidth, pHeight };

        int running = 1;
        while (running) {
            clear(r);

            renderBackground(r, -x, -y);

            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
            SDL_RenderFillRect(r, &p);

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
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

