#include "goblinfactory.h"

Goblin *GoblinFactory::createUnit(int x, int y, QPixmap image)
{
    return new Goblin(x, y, image);
}
