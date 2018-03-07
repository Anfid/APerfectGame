#ifndef GAME_H
#define GAME_H

#include "Player.h"

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

    Player *player;
};

#endif // GAME_H
