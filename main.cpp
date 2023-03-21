#include <iostream>
#include <SDL3/SDL.h>



int main() {
    std::cout << "Bonjour!\n";

    SDL_Init(SDL_INIT_VIDEO);

    auto window = SDL_CreateWindow("test", 500, 500, SDL_WINDOW_OPENGL);

    if (window == NULL) {
        std::cout << "test\n";
    } else {
        auto screenSurface = SDL_GetWindowSurface(window);

        auto r = SDL_CreateRenderer(window, "ab", SDL_RENDERER_ACCELERATED);

        SDL_SetRenderDrawColor(r, 96, 128, 255, 255);


        SDL_RenderPresent(r);

        while (1) {
            SDL_SetRenderDrawColor(r, 96, 128, 255, 255);
	        SDL_RenderClear(r);

            SDL_Event event;

            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_EVENT_QUIT:
                        exit(0);
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

