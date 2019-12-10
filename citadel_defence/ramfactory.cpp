#include "ramfactory.h"

Ram *RamFactory::createUnit(int x, int y, QPixmap image)
{
    return new Ram(x, y, image);
}
