#ifndef RAM_H
#define RAM_H

#include "movingobject.h"
#include "attack.h"

class Ram: public MovingObject
{
public:
    Ram(int x, int y, QPixmap image);
    ~Ram() override final = default;
    void damageAt(StaticObject* target) override final;
};

#endif // RAM_H
