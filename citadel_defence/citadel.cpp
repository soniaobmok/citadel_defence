#include "citadel.h"

Citadel::Citadel(int x, int y, QPixmap image): StaticObject (x, y, image)
{
    this->setHp(5000);
    this->setWidth(336);
    this->setHeight(330);
}
