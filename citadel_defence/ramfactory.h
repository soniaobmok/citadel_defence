#ifndef RAMFACTORY_H
#define RAMFACTORY_H

#include "unitfactory.h"
#include "ram.h"

class RamFactory: public UnitFactory
{
public:
    Ram* createUnit(int, int, QPixmap) override final;
};

#endif // RAMFACTORY_H
