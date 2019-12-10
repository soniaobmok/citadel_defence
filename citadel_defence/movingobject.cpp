#include "movingobject.h"

MovingObject::MovingObject(int x, int y, QPixmap image): StaticObject (x, y, image)
{
    moveTarget = new StaticObject();
    moveTarget->setX(0);
    moveTarget->setY(0);
    isMoving = true;
}

void MovingObject::move(StaticObject* target)
{
    int distance = static_cast<int>(sqrt((this->getX() - target->getX()) * (this->getX() - target->getX()) +
                                         (this->getY() - target->getY()) * (this->getY() - target->getY())));
    if (this->getRange() < distance)
    {
        int vecX = target->getX() - this->getX();
        int vecY = target->getY() - this->getY();
        int vecLength = static_cast<int>(sqrt(vecX * vecX + vecY * vecY));
        int unitVecX = static_cast<int>(2 * vecX / vecLength);
        int unitVecY = static_cast<int>(2 * vecY / vecLength);
        int stepX = unitVecX * this->getSpeed();
        int stepY = unitVecY * this->getSpeed();
        setCoordinates(this->getX() + stepX, this->getY() + stepY);
    }
}

int MovingObject::getSpeed() const
{
    return speed;
}

void MovingObject::setCoordinates(int x, int y)
{
    this->setX(x);
    this->setY(y);
}

void MovingObject::setMoveTarget(int x, int y)
{
    moveTarget->setX(x);
    moveTarget->setY(y);
}

StaticObject *MovingObject::getMoveTarget() const
{
    return moveTarget;
}

bool MovingObject::getIsMoving() const
{
    return isMoving;
}

void MovingObject::setIsMoving(bool value)
{
    isMoving = value;
}

void MovingObject::setSpeed(int value)
{
    speed = value;
}
