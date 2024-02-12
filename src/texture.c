#include "texture.h"

Texture2D loadTexture(const char* textureName) {
    const Image image = LoadImage(textureName);
    const Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    return texture;
}