#ifndef CATAPULTFACTORY_H
#define CATAPULTFACTORY_H

#include "unitfactory.h"
#include "catapult.h"

class CatapultFactory: public UnitFactory
{
public:
    Catapult* createUnit(int, int, QPixmap) override final;
};

#endif // CATAPULTFACTORY_H
