#include "staticobject.h"

StaticObject::StaticObject(int x, int y, QPixmap image)
{
    this->x = x;
    this->y = y;
    this->image = image;
    this->height = 50;
    this->width = 50;
    isAlive = true;
}

int StaticObject::getX()
{
    return x;
}

int StaticObject::getY()
{
    return y;
}

int StaticObject::getHeight()
{
    return height;
}

int StaticObject::getWidth()
{
    return width;
}

void StaticObject::draw(QPainter* painter)
{
    painter->drawPixmap(this->getX(), this->getY(), this->getImage());
}

int StaticObject::getHp() const
{
    return hp;
}

void StaticObject::setHp(int value)
{
    hp = value;
}

QPixmap StaticObject::getImage() const
{
    return image;
}

void StaticObject::setImage(const QPixmap &value)
{
    image = value;
}

void StaticObject::setX(int value)
{
    x = value;
}

void StaticObject::setY(int value)
{
    y = value;
}

bool StaticObject::getIsAlive() const
{
    return isAlive;
}

void StaticObject::setIsAlive(bool value)
{
    isAlive = value;
}

void StaticObject::setWidth(int value)
{
    width = value;
}

void StaticObject::setHeight(int value)
{
    height = value;
}

