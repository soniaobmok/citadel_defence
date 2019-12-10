#ifndef ORCFACTORY_H
#define ORCFACTORY_H

#include "unitfactory.h"
#include "orc.h"

class OrcFactory: public UnitFactory
{
public:
    Orc* createUnit(int, int, QPixmap) override final;
};

#endif // ORCFACTORY_H
