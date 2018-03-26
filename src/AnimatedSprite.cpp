#include "AnimatedSprite.h"

#include "Graphics.h"

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &spritePath, double positionX, double positionY) :
        Sprite(graphics, spritePath, positionX, positionY),
        frameIndex(0),
        frameTime(0),
        frameTimeToUpdate(200)
{}

AnimatedSprite::~AnimatedSprite() = default;

void AnimatedSprite::addAnimation(std::string name, int firstFrameX, int firstFrameY, int frameWidth, int frameHeight,
                                  int framesAmount, int animationSpeed) {
    std::vector<SDL_Rect> rectangles;

    // first rect with animation info. x contains frame time to update
    SDL_Rect info = {animationSpeed, 0, 0, 0};
    rectangles.push_back(info);
    for (int i = 0; i <= framesAmount; ++i) {
        SDL_Rect newRect = {i * frameWidth + firstFrameX, firstFrameY, frameWidth, frameHeight};
        rectangles.push_back(newRect);
    }
    this->animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
}

void AnimatedSprite::playAnimation(const std::string &animation) {
    this->frameTimeToUpdate = this->animations[this->currentAnimation][0].x;
    if (this->currentAnimation != animation) {
        this->currentAnimation = animation;
        this->frameIndex = 0;
    }
}

void AnimatedSprite::update(int elapsedTime) {
    this->frameTime += elapsedTime;
    if (this->frameTime > this->frameTimeToUpdate) {
        if (this->frameIndex < this->animations[this->currentAnimation].size() - 2) {
            this->frameIndex++;
        } else {
            this->frameIndex = 1;
        }
        this->sourceRect = this->animations[this->currentAnimation][this->frameIndex];
        this->frameTime -= this->frameTimeToUpdate;
    }
}
