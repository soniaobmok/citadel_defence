#ifndef BARRICADEFACTORY_H
#define BARRICADEFACTORY_H

#include "unitfactory.h"
#include "barricade.h"

class BarricadeFactory: public UnitFactory
{
public:
    Barricade* createUnit(int, int, QPixmap) override final;
};

#endif // BARRICADEFACTORY_H
