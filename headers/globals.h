#ifndef GLOBALS_H
#define GLOBALS_H

namespace globals {
    const int windowWidth = 1024;
    const int windowHeight = 768;
    const float spriteScale = 2;
}

enum Direction {
    left,
    right
};

struct pointDouble {
    double x, y;
};

#endif // GLOBALS_H
