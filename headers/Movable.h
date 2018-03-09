#ifndef MOVABLE_H
#define MOVABLE_H

#include "globals.h"

class Movable {
protected:
    Movable();

    /* void accelerate(double x, double y)
     * Increase vector.x by x and vector.y by y.
     * If NULL passed, corresponding value won't change
     */
    void accelerate(double x, double y);

    /* void setVector(double x, double y)
     * Set vector.x to x and vector.y to y.
     * If NULL passed, corresponding value won't change
     */
    void setVector(double x, double y);

    void stop(bool x = true, bool y = true);

    const pointDouble& getVector();

private:
    pointDouble vector;
};

#endif // MOVABLE_H
