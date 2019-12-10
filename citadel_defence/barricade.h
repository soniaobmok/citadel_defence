#ifndef BARRICADE_H
#define BARRICADE_H

#include "staticobject.h"

class Barricade: public StaticObject
{
public:
    Barricade(int x, int y, QPixmap image);
    ~Barricade() override final = default;
};

#endif // BARRICADE_H
