#ifndef GAME_H
#define GAME_H

#include "AnimatedSprite.h"

class Graphics;
class Input;
class Scroll;

enum State {
    Menu,
    Play,
    Pause
};

class Game {
public:
    Game();
    ~Game();

private:
    void mainLoop();
    void draw(Graphics &graphics, Scroll &scroll);
    void update(Graphics &graphics, Input &input, Scroll &scroll, int elapsedTime);
    void reset();

    AnimatedSprite *sprite;
};

#endif // GAME_H
