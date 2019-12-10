#include "orcfactory.h"

Orc *OrcFactory::createUnit(int x, int y, QPixmap image)
{
    return new Orc(x, y, image);
}
