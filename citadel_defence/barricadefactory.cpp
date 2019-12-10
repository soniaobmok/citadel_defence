#include "barricadefactory.h"

Barricade *BarricadeFactory::createUnit(int x, int y, QPixmap image)
{
    return new Barricade(x, y, image);
}
