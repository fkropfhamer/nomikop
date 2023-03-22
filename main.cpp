#include <iostream>
#include <SDL3/SDL.h>


int main() {
    std::cout << "Bonjour!\n";

    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("test", 500, 500, 0);

    if (window == NULL) {
        std::cout << "test\n";
        std::cout << SDL_GetError();
    } else {
        auto screenSurface = SDL_GetWindowSurface(window);

        auto r = SDL_CreateRenderer(window, NULL, 0);
        if (r == NULL) {
            std::cout << "fail\n";
            std::cout << SDL_GetError();
        }

        auto running = true;
        auto i = 0;
        auto flip = true;
        while (running) {
            i++;

            if (flip) {
                SDL_SetRenderDrawColor(r, 0, 255, 0, 255);    
            } else {
                SDL_SetRenderDrawColor(r, 0, 0, 255, 255);
            }
            
	        SDL_RenderClear(r);

            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_EVENT_QUIT:
                        running = false;
                        break;

                    case SDL_EVENT_KEY_UP:
                        std::cout << "key\n";
                        flip = !flip;
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

