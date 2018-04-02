#include "AnimatedSprite.h"

#include "Graphics.h"

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &spritePath, int positionX, int positionY) :
        Sprite(graphics, spritePath, positionX, positionY),
        frameIndex(0),
        frameTime(0),
        frameTimeToUpdate(200)
{}

AnimatedSprite::~AnimatedSprite() = default;

void AnimatedSprite::addAnimation(std::string name, int firstFrameX, int firstFrameY, int frameWidth, int frameHeight,
                                  int framesAmount, int animationSpeed) {
    std::vector<SDL_Rect> rectangles;

    for (int i = 0; i < framesAmount; ++i) {
        SDL_Rect newRect = {i * frameWidth + firstFrameX, firstFrameY, frameWidth, frameHeight};
        rectangles.push_back(newRect);
    }
    auto animation = std::pair<AnimationInfo, std::vector<SDL_Rect>>(AnimationInfo{animationSpeed}, rectangles);
    this->animations.insert(std::pair<std::string, std::pair<AnimationInfo, std::vector<SDL_Rect>>>(name, animation));
}

void AnimatedSprite::playAnimation(const std::string &animation) {
    this->frameTimeToUpdate = this->animations[this->currentAnimation].first.speed;
    if (this->currentAnimation != animation) {
        this->currentAnimation = animation;
        this->frameTime = 0;
        this->frameIndex = 0;
        this->nextFrame();
    }
}

void AnimatedSprite::update(int elapsedTime) {
    this->frameTime += elapsedTime;
    if (this->frameTime > this->frameTimeToUpdate) {
        this->nextFrame();
        this->frameTime -= this->frameTimeToUpdate;
    }
}

void AnimatedSprite::nextFrame() {
    if (this->frameIndex < this->animations[this->currentAnimation].second.size() - 1) {
        this->frameIndex += 1;
    } else {
        this->frameIndex = 0;
    }
    this->sourceRect = this->animations[this->currentAnimation].second[this->frameIndex];
}
