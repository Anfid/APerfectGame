#include "Player.h"

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

void Player::walk(double x) {
    if (x < 0) {
        this->direction = left;
        this->delta.x = -this->moveSpeed; // todo later: add buffs and debuffs affecting player
    } else if (x > 0) {
        this->direction = right;
        this->delta.x = this->moveSpeed;
    }
}

void Player::update(int elapsedTime) {
    AnimatedSprite::update(elapsedTime);
    static int timeAfterUpdate;
    timeAfterUpdate += elapsedTime;
    if (timeAfterUpdate > 20) {
        this->position.x += this->delta.x;
        this->delta.x = 0;
        timeAfterUpdate = 0;
    }
}
