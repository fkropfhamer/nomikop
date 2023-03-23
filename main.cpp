#include <iostream>
#include <SDL3/SDL.h>


int main() {
    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("test", 500, 500, 0);

    if (window == NULL) {
        std::cout << "test\n";
        std::cout << SDL_GetError() << "\n";
    } else {
        auto r = SDL_CreateRenderer(window, NULL, 0);
        if (r == NULL) {
            std::cout << "fail\n";
            std::cout << SDL_GetError() << "\n";
        }

        SDL_FRect p = { 100, 100, 50, 100 };
        
        auto running = true;
        auto flip = true;
        while (running) {
            if (flip) {
                SDL_SetRenderDrawColor(r, 0, 255, 0, 255);    
            } else {
                SDL_SetRenderDrawColor(r, 0, 0, 255, 255);
            }

            SDL_RenderClear(r);

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
                            p.x -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                            std::cout << "right\n";
                            p.x += 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_UP) {
                            std::cout << "up\n";
                            p.y -= 5;
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_DOWN) {
                            p.y += 5;
                            std::cout << "down\n";
                        }
                        if (event.key.keysym.scancode == SDL_SCANCODE_C) {
                            flip = !flip;
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

