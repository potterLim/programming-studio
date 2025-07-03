#include "Circle.h"

Circle::Circle(int radius)
    : mRadius(radius)
{
}

double Circle::GetArea() const
{
    return 3.14 * mRadius * mRadius;
}