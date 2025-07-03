#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
    Rectangle(int width, int height);
    int GetArea() const;
    int GetPerimeter() const;

private:
    int mWidth;
    int mHeight;
};

#endif // RECTANGLE_H