#include "Player.h"

#include "Graphics.h"

Player::Player(Graphics &graphics, int positionX, int positionY) :
        AnimatedSprite(graphics, "../content/sprites/anhero.png", positionX, positionY),
        Movable(),
        direction(right),
        grounded(true),
        moveSpeed(1)
{
    this->addAnimation("Idle", 0, 0, 16, 20, 4, 200);
    this->addAnimation("Run", 0, 20, 16, 20, 6, (int)(250 / this->moveSpeed));
    this->currentAnimation = "Idle";
}

void Player::walk(Direction direction) {
    this->direction = direction;
    switch(direction) {
        case left:
            this->setVector(-this->moveSpeed, 0); // todo later: add buffs and debuffs affecting player
            break;

        case right:
            this->setVector(this->moveSpeed, 0);
            break;
    }
}

void Player::stop() {
    Movable::stop();
}

void Player::updateAnimations() {
    if (this->grounded) {
        if (this->getVector().x == 0) {
            this->playAnimation("Idle");
        } else {
            this->playAnimation("Run");
            this->animations["Run"].first.speed = (int)(250 / this->moveSpeed);
        }
    }
}

void Player::update(int elapsedTime) {
    AnimatedSprite::update(elapsedTime);
    static int timeAfterUpdate;
    timeAfterUpdate += elapsedTime;
    if (timeAfterUpdate > 20) {
        this->updateAnimations();
        this->position.x += this->getVector().x;
        timeAfterUpdate = 0;
    }
}

void Player::draw(Graphics &graphics) {
    SDL_Rect destRect{(int)std::lround(this->position.x), (int)std::lround(this->position.y),
                      (int)(this->sourceRect.w * globals::spriteScale),
                      (int)(this->sourceRect.h * globals::spriteScale)};
    graphics.blitSurface(*this->spriteSheet, this->sourceRect, destRect, this->direction == left);
}
