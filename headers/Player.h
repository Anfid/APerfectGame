#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "AnimatedSprite.h"
#include "Movable.h"

class Player : public AnimatedSprite, private Movable  {
public:
    Player(Graphics &graphics, int positionX, int positionY);
    void walk(double x);

    void update(int elapsedTime) override;

protected:
    Direction direction;
    double moveSpeed;
};

#endif // PLAYER_H
