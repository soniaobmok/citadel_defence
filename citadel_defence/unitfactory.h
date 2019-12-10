#ifndef UNITFACTORY_H
#define UNITFACTORY_H

#include "staticobject.h"
#include <iostream>

class UnitFactory {
public:
    virtual StaticObject* createUnit(int, int, QPixmap) = 0;
    virtual ~UnitFactory() = default;
};

#endif // UNITFACTORY_H
