#ifndef GOBLIN_H
#define GOBLIN_H

#include "movingobject.h"
#include "attack.h"

class Goblin: public MovingObject
{
public:
    Goblin(int x, int y, QPixmap image);
    ~Goblin() override final = default;
    void damageAt(StaticObject* target) override final;
    void move(StaticObject* target) override final;
};

#endif // GOBLIN_H
