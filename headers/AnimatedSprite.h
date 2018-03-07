#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>
#include <map>

#include "Sprite.h"

class AnimatedSprite : public Sprite {
public:
    AnimatedSprite(Graphics &graphics, const std::string &spritePath, int positionX, int positionY);
    ~AnimatedSprite() override;

    void playAnimation(const std::string &animationName);

    virtual void update(int elapsedTime);
    void draw(Graphics &graphics) override;

protected:
    void addAnimation(std::string name, int firstFrameX, int firstFrameY, int frameWidth, int frameHeight, int framesAmount,
                          int animationSpeed);

    std::string currentAnimation;
    int frameIndex;
    int frameTime;
    int frameTimeToUpdate;

    std::map<std::string, std::vector<SDL_Rect>> animations;
};

#endif // ANIMATEDSPRITE_H
