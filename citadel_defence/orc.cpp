#include "orc.h"

Orc::Orc(int x, int y, QPixmap image): MovingObject (x, y, image)
{
    this->setSpeed(2);
    this->range = 50;
    this->setHp(500);
    this->damage = 15;
}

void Orc::damageAt(StaticObject* target)
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
