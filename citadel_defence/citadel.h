#ifndef CITADEL_H
#define CITADEL_H

#include "staticobject.h"

class Citadel: public StaticObject
{
public:
    Citadel(int x, int y, QPixmap image);
    ~Citadel() override final = default;
};

#endif // CITADEL_H
