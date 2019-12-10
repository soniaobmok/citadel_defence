#ifndef KNIGHTFACTORY_H
#define KNIGHTFACTORY_H

#include "unitfactory.h"
#include "knight.h"

class KnightFactory: public UnitFactory
{
public:
    Knight* createUnit(int, int, QPixmap) override final;
};

#endif // KNIGHTFACTORY_H
