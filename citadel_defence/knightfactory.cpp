#include "knightfactory.h"

Knight *KnightFactory::createUnit(int x, int y, QPixmap image)
{
    return new Knight(x, y, image);
}
