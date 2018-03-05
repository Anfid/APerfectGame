#ifndef PLAYER_H
#define PLAYER_H

#include "AnimatedSprite.h"
#include "Movable.h"

class Player : private Movable, public AnimatedSprite {
    Player(); // empty yet
};

#endif // PLAYER_H
