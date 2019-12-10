#ifndef ATTACK_H
#define ATTACK_H

#include "staticobject.h"

class Attack
{
public:
    virtual ~Attack() = default;
    virtual void damageAt(StaticObject* target) = 0;
    int getRange() const;
    int getDamage() const;


protected:
    int range = 0;
    int damage = 0;
    StaticObject* attackTarget;
};

#endif // ATTACK_H
