#ifndef POSITIONAL_H
#define POSITIONAL_H

class Positional
{
public:
    virtual ~Positional() = default;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual int getHeight() = 0;
    virtual int getWidth() = 0;
};

#endif // POSITIONAL_H
