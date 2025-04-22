#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product
{
public:
    Product();

    void Input();
    void Print() const;

private:
    string mName;
    int mOriginalPrice;
    int mDiscountPercent;
    string mSize;
    string mManufacturer;
};

#endif // PRODUCT_H