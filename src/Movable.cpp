#include "Movable.h"

Movable::Movable() :
        delta{0, 0}
{}

void Movable::moveX(double x) {
    this->delta.x = x;
}

void Movable::moveY(double y) {

}
