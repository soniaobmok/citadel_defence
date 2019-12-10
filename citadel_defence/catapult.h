#ifndef CATAPULT_H
#define CATAPULT_H

#include "movingobject.h"
#include "attack.h"

class Catapult: public MovingObject
{
public:
    Catapult(int x, int y, QPixmap image);
    ~Catapult() override final = default;
    void damageAt(StaticObject* target) override final;
};

#endif // CATAPULT_H
