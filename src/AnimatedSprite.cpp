#include "AnimatedSprite.h"

#include "Graphics.h"

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &spritePath, int positionX, int positionY) :
        Sprite(graphics, spritePath, positionX, positionY),
        frameIndex(0),
        frameTime(0),
        frameTimeToUpdate(200)
{}

AnimatedSprite::~AnimatedSprite() = default;

void AnimatedSprite::addAnimation(std::string name, int x, int y, int height, int width, int frames) {
    std::vector<SDL_Rect> rectangles;
    for (int i = 0; i < frames; ++i) {
        SDL_Rect newRect = {i * width + x, y, width, height};
        rectangles.push_back(std::move(newRect));
    }
    this->animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectangles));
}

void AnimatedSprite::playAnimation(const std::string &animation) {
    if (this->currentAnimation != animation) {
        this->currentAnimation = animation;
        this->frameIndex = 0;
    }
}

void AnimatedSprite::update(int elapsedTime) {
    this->frameTime += elapsedTime;
    if (this->frameTime > this->frameTimeToUpdate) {
        if (this->frameIndex < this->animations[this->currentAnimation].size() - 1) {
            this->frameIndex++;
        } else {
            this->frameIndex = 0;
        }
        this->sourceRect = this->animations[this->currentAnimation][this->frameIndex];
        this->frameTime -= this->frameTimeToUpdate;
    }
}

void AnimatedSprite::draw(Graphics &graphics) {
    Sprite::draw(graphics);
}