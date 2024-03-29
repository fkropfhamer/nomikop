#ifndef NOMIKOP_RENDERER_HPP
#define NOMIKOP_RENDERER_HPP


#include "SDL.h"

class Renderer {
private:
    SDL_Renderer *renderer{};

public:
    explicit Renderer(SDL_Renderer *renderer);
    void clear();
    void present();
    void renderBackground(int offSetX, int offSetY);
};


#endif