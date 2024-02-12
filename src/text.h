#ifndef TEXT_H
#define TEXT_H

#include <SDL3/SDL_ttf.h>

TTF_Font* initFont();
SDL_Texture* createTextTexture(TTF_Font* font, SDL_Renderer* r, const char* text);

#endif //TEXT_H
