#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include <map>

#include "Sprite.h"

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite(Graphics &graphics, const std::string &spritePath, double positionX, double positionY);
    ~AnimatedSprite() override;

    void playAnimation(const std::string &animationName);

    virtual void update(int elapsedTime);

protected:
    void addAnimation(std::string name, int firstFrameX, int firstFrameY, int frameWidth, int frameHeight,
                      int framesAmount, int animationSpeed);
    void nextFrame();

    std::string currentAnimation;
    int frameIndex;
    int frameTime;
    int frameTimeToUpdate;

    struct AnimationInfo {
        int speed;
    };
    std::map<std::string, std::pair<AnimationInfo, std::vector<SDL_Rect>>> animations;
};

#endif // ANIMATEDSPRITE_H
