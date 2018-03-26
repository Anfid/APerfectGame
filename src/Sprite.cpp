#include "Sprite.h"

#include <cmath>
#include "SDL.h"

#include "Graphics.h"

Sprite::Sprite(Graphics &graphics, const std::string &spritePath, double positionX, double positionY) :
        spriteSheet(graphics.createTexture(spritePath)),
        sourceRect{0, 0, 0, 0},
        position{positionX, positionY}
{}

Sprite::Sprite(Graphics &graphics, const std::string &spritePath, int sourceX, int sourceY,
               int sourceW, int sourceH, double positionX, double positionY) :
        spriteSheet(graphics.createTexture(spritePath)),
        sourceRect{sourceX, sourceY, sourceW, sourceH},
        position{positionX, positionY}
{}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->spriteSheet);
}

void Sprite::draw(Graphics &graphics) {
    SDL_Rect destRect{static_cast<int>(std::lround(position.x)), static_cast<int>(std::lround(position.y)), static_cast<int>(this->sourceRect.w * globals::spriteScale),
                      static_cast<int>(this->sourceRect.h * globals::spriteScale)};
    graphics.blitSurface(*this->spriteSheet, this->sourceRect, destRect);
}
