#include "Rectangle.h"

Rectangle::Rectangle(int width, int height)
    : mWidth(width)
    , mHeight(height)
{
}

int Rectangle::GetArea() const
{
    return mWidth * mHeight;
}

int Rectangle::GetPerimeter() const
{
    return 2 * (mWidth + mHeight);
}