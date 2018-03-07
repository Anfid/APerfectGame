#include "Sprite.h"

#include <cmath>
#include "SDL.h"

#include "Graphics.h"

Sprite::Sprite(Graphics &graphics, const std::string &spritePath, int positionX, int positionY) :
        spriteSheet(graphics.createTexture(spritePath)),
        sourceRect{0, 0, 0, 0},
        position{positionX, positionY}
{}

Sprite::Sprite(Graphics &graphics, const std::string &spritePath, int sourceX, int sourceY,
               int sourceW, int sourceH, int positionX, int positionY) :
        spriteSheet(graphics.createTexture(spritePath)),
        sourceRect{sourceX, sourceY, sourceW, sourceH},
        position{positionX, positionY}
{}

Sprite::~Sprite() {
    SDL_DestroyTexture(this->spriteSheet);
}

void Sprite::draw(Graphics &graphics) {
    SDL_Rect destRect{std::lround(position.x), std::lround(position.y), (int)(this->sourceRect.w * globals::spriteScale),
                      (int)(this->sourceRect.h * globals::spriteScale)};
    graphics.blitSurface(*this->spriteSheet, this->sourceRect, destRect);
}
