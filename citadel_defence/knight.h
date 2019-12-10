#ifndef KNIGHT_H
#define KNIGHT_H

#include "movingobject.h"
#include "attack.h"

class Knight: public MovingObject
{
public:
    Knight(int x, int y, QPixmap image);
    ~Knight() override final = default;
    void damageAt(StaticObject* target) override final;
};

#endif // KNIGHT_H
