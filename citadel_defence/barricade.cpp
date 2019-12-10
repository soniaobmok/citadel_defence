#include "barricade.h"

Barricade::Barricade(int x, int y, QPixmap image): StaticObject (x, y, image)
{
    this->setHp(3000);
}
