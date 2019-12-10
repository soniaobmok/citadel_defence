#ifndef ORC_H
#define ORC_H

#include "movingobject.h"
#include "attack.h"

class Orc: public MovingObject
{
public:
    Orc(int x, int y, QPixmap image);
    ~Orc() override final = default;
    void damageAt(StaticObject* target) override final;
};

#endif // ORC_H
