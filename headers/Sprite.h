#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL_rect.h>

#include "globals.h"

struct SDL_Texture;
class Graphics;

class Sprite {
public:
    Sprite(Graphics &graphics, const std::string &spritePath, int positionX, int positionY);
    Sprite(Graphics &graphics, const std::string &spritePath, int sourceX, int sourceY, int sourceW, int sourceH, int positionX, int positionY);
    virtual ~Sprite();

    virtual void draw(Graphics &graphics);

protected:
    SDL_Texture *spriteSheet;
    SDL_Rect sourceRect;

    pointDouble position;
};

#endif // SPRITE_H
