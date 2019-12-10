#include "catapult.h"

Catapult::Catapult(int x, int y, QPixmap image): MovingObject (x, y, image)
{
    this->setSpeed(1);
    this->range = 250;
    this->setHp(500);
    this->damage = 10;
}

void Catapult::damageAt(StaticObject* target)
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


