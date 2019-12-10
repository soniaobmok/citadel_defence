#include "catapultfactory.h"

Catapult *CatapultFactory::createUnit(int x, int y, QPixmap image)
{
    return new Catapult(x, y, image);
}
