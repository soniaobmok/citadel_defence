#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "drawable.h"
#include "positional.h"

class StaticObject: public Positional, public Drawable
{
public:
    StaticObject() = default;
    StaticObject(int x, int y, QPixmap image);
    ~StaticObject() override = default;
    int getX() override final;
    int getY() override final;
    int getHeight() override final;
    int getWidth() override final;
    void setWidth(int value);
    void setHeight(int value);
    void draw(QPainter *) override;

    int getHp() const;
    void setHp(int value);

    QPixmap getImage() const;
    void setImage(const QPixmap &value);

    void setX(int value);

    void setY(int value);

    bool getIsAlive() const;
    void setIsAlive(bool value);




private:
    int hp;
    int x, y;
    int width, height;
    QPixmap image;
    bool isAlive;
};

#endif // STATICOBJECT_H
