#include "Player.h"

#include "Graphics.h"

Player::Player(Graphics &graphics, int positionX, int positionY) :
        AnimatedSprite(graphics, "../content/sprites/anhero.png", positionX, positionY),
        Movable(),
        direction(right),
        moveSpeed(3)
{
    this->addAnimation("Idle", 0, 0, 16, 20, 4, 200);
    this->addAnimation("Run", 0, 20, 16, 20, 6, 150);
    this->currentAnimation = "Idle";
}

void Player::walk(Direction direction) {
    this->direction = direction;
    this->playAnimation("Run");
    switch(direction) {
        case left:
            this->moveX(-this->moveSpeed); // todo later: add buffs and debuffs affecting player
            break;

        case right:
            this->moveX(this->moveSpeed);
            break;
    }
}

void Player::update(int elapsedTime) {
    AnimatedSprite::update(elapsedTime);
    static int timeAfterUpdate;
    timeAfterUpdate += elapsedTime;
    if (timeAfterUpdate > 20) {
        if (this->delta.x == 0) {
            this->playAnimation("Idle");
        } else {
            this->position.x += this->delta.x;
            this->delta.x = 0;
        }
        timeAfterUpdate = 0;
    }
}

void Player::draw(Graphics &graphics) {
    SDL_Rect destRect{std::lround(position.x), std::lround(position.y), (int)(this->sourceRect.w * globals::spriteScale),
                      (int)(this->sourceRect.h * globals::spriteScale)};
    graphics.blitSurface(*this->spriteSheet, this->sourceRect, destRect, this->direction == left);
}
