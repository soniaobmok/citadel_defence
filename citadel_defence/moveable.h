#ifndef MOVEABLE_H
#define MOVEABLE_H

#include "staticobject.h"

class Moveable
{
public:
    virtual ~Moveable() = default;
    virtual void move(StaticObject* target) = 0;
    virtual void setCoordinates(int x, int y) = 0;
    virtual void setMoveTarget(int x, int y) = 0;
};

#endif // MOVEABLE_H
