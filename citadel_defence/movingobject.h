#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "staticobject.h"
#include "moveable.h"
#include "attack.h"

class MovingObject: public StaticObject, public Moveable, public Attack
{
public:
    MovingObject(int x, int y, QPixmap image);
    ~MovingObject() override = default;
    void move(StaticObject* target) override;
    int getSpeed() const;    
    void setSpeed(int value);
    void setCoordinates(int x, int y) override final;
    void setMoveTarget(int x, int y) override;

    StaticObject *getMoveTarget() const;

    bool getIsMoving() const;
    void setIsMoving(bool value);


private:
    int speed;
    StaticObject* moveTarget;
    bool isMoving;
};

#endif // MOVINGOBJECT_H
