#include <SDL.h>

#include "Game.h"
#include "Input.h"
#include "Graphics.h"
#include "Scroll.h"

namespace {
    const int FPS = 50;
    const int FRAME_TIME = 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->mainLoop();
}

Game::~Game() {
    this->reset();
}

void Game::mainLoop() {
    // ------------------------------ Setup ------------------------------

    SDL_Event event;

    Graphics graphics;
    Scroll scroll;
    Input input;

    this->player = new Player(graphics, 50, 50);
    this->player->playAnimation("Run");

    int lastUpdateTime = SDL_GetTicks();

    // ------------------------------ Game loop ------------------------------
    while (true) {
        input.beginNewFrame(event);

        // Handle input, may be add Controls class later
        if (input.isKeyHeld(SDL_SCANCODE_A)) {
            this->player->walk(left);
        } else if (input.isKeyHeld(SDL_SCANCODE_D)) {
            this->player->walk(right);
        }
        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }

        const int currentTime = SDL_GetTicks();
        int elapsedTime = currentTime - lastUpdateTime;
        this->update(graphics, input, scroll, elapsedTime);
        lastUpdateTime = currentTime;
    }
}

void Game::update(Graphics &graphics, Input &input, Scroll &scroll, int elapsedTime) {
    static int timeAfterUpdate;
    timeAfterUpdate += elapsedTime;

    scroll.update(graphics, input);

    this->player->update(elapsedTime);

    if (timeAfterUpdate > FRAME_TIME) {
        this->draw(graphics, scroll);
        timeAfterUpdate -= FRAME_TIME;
    }
};

void Game::draw(Graphics &graphics, Scroll &scroll) {
    graphics.clear();

    this->player->draw(graphics);

    graphics.flip();
}

void Game::reset() {}
