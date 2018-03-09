#include "Movable.h"

Movable::Movable() :
        vector{0, 0}
{}

void Movable::accelerate(double x, double y) {
    if (x) this->vector.x += x;
    if (y) this->vector.y += y;
}

void Movable::setVector(double x, double y) {
    if (x) this->vector.x = x;
    if (y) this->vector.y = y;
}

void Movable::stop(bool x, bool y) {
    if (x) this->vector.x = 0;
    if (y) this->vector.y = 0;
}

const pointDouble& Movable::getVector() {
    return this->vector;
}
