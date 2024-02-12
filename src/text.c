#include "text.h"

TTF_Font* initFont() {
    if (TTF_Init() == -1) {
        printf("%s\n", TTF_GetError());

        return NULL;
    }

    TTF_Font* font = TTF_OpenFont("./assets/fonts/FiraSans-Black.ttf", 256);
    if (font == NULL) {
        printf("%s\n", TTF_GetError());
    }

    return font;
}

SDL_Texture* createTextTexture(TTF_Font* font, SDL_Renderer* r, const char* text) {
    const SDL_Color white = {255, 255, 255};
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid(font, text, white);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(r, textSurface);
    SDL_DestroySurface(textSurface);

    return textTexture;
}
