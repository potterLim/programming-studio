#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
public:
    Circle(int radius);
    double GetArea() const;

private:
    int mRadius;
};

#endif /* CIRCLE_H */