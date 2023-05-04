#include <iostream>
#include <SDL3/SDL.h>

void renderBackground(SDL_Renderer *renderer, int offSetX, int offSetY) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

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

int main() {
    std::cout << "test\n";
    SDL_Init(SDL_INIT_VIDEO);

    const int width = 500;
    const int height = 500;

    auto window = SDL_CreateWindow("nomikop", width, height, 0);

    if (window == nullptr) {
        std::cout << "test\n";
        std::cout << SDL_GetError() << "\n";
    } else {
        auto r = SDL_CreateRenderer(window, nullptr, 0);
        if (r == nullptr) {
            std::cout << "fail\n";
            std::cout << SDL_GetError() << "\n";
        }

        int x = 0;
        int y = 0;

        float pHeight = 40;
        float pWidth = 25;
        SDL_FRect p = { width / 2 - pWidth , height / 2 - pHeight, pWidth, pHeight };

        auto running = true;
        while (running) {
            SDL_SetRenderDrawColor(r, 0, 0, 0, 255);

            SDL_RenderClear(r);

            renderBackground(r, -x, -y);

            SDL_SetRenderDrawColor(r, 255, 0, 0, 255);
            SDL_RenderFillRect(r, &p);

            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_EVENT_QUIT:
                        running = false;
                        break;

                    case SDL_EVENT_KEY_UP:
                        std::cout << "key\n";
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

            SDL_RenderPresent(r);
            SDL_Delay(20);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

