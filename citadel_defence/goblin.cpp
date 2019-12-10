#include "goblin.h"

Goblin::Goblin(int x, int y, QPixmap image): MovingObject (x, y, image)
{
    this->setHp(200);
    this->damage = 5;
    this->range = 350;
    this->setSpeed(0);
}

void Goblin::damageAt(StaticObject *target)
{
    int distance = static_cast<int>(sqrt((this->getX() - target->getX()) * (this->getX() - target->getX()) +
                                         (this->getY() - target->getY()) * (this->getY() - target->getY())));
    if (distance <= this->range)
    {
        target->setHp(target->getHp() - this->damage);
    }
}

void Goblin::move(StaticObject *target)
{
    Q_UNUSED(target);
}
