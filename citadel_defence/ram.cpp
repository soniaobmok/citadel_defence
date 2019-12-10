#include "ram.h"

Ram::Ram(int x, int y, QPixmap image): MovingObject (x, y, image)
{
    this->setSpeed(1);
    this->range = 50;
    this->setHp(500);
    this->damage = 40;
}

void Ram::damageAt(StaticObject *target)
{
    int distance = static_cast<int>(sqrt((this->getX() - target->getX()) * (this->getX() - target->getX()) +
                                         (this->getY() - target->getY()) * (this->getY() - target->getY())));
    if (distance <= this->range)
    {
        this->setIsMoving(false);
        target->setHp(target->getHp() - this->damage);
    }
    else {
        this->setIsMoving(true);
    }
}
