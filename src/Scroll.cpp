#include <globals.h>
#include <Input.h>
#include <Graphics.h>
#include "SDL.h"
#include "Scroll.h"

Scroll::Scroll() :
        delta{0, 0}
{}

Scroll::~Scroll() = default;

void Scroll::update(Graphics &graphics, Input &input) {
    /*
     * Uncomment following lines if window size is required
     */
    // int windowWidth, windowHeight;
    // SDL_GetWindowSize(graphics.getWindow(), &windowWidth, &windowHeight);
}

const SDL_Point* Scroll::getDelta() const {
    return &this->delta;
}
