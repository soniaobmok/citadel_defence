#ifndef GOBLINFACTORY_H
#define GOBLINFACTORY_H

#include "unitfactory.h"
#include "goblin.h"

class GoblinFactory: public UnitFactory
{
public:
    Goblin* createUnit(int, int, QPixmap) override final;
};

#endif // GOBLINFACTORY_H
