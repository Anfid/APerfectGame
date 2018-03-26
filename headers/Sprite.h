#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL_rect.h>

#include "globals.h"

struct SDL_Texture;
class Graphics;

class Sprite {
public:
    Sprite(Graphics &graphics, const std::string &spritePath, double positionX, double positionY);
    Sprite(Graphics &graphics, const std::string &spritePath, int sourceX, int sourceY, int sourceW, int sourceH, double positionX, double positionY);
    virtual ~Sprite();

    virtual void draw(Graphics &graphics);

protected:
    SDL_Texture *spriteSheet;
    SDL_Rect sourceRect;

    pointDouble position;
};

#endif // SPRITE_H
