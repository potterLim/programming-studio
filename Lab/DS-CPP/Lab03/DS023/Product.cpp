#include "Product.h"
#include <cstdio>

Product::Product()
    : mOriginalPrice(0)
    , mDiscountPercent(0)
{
}

void Product::Input()
{
    cin.ignore();
    getline(cin, mName);
    cin >> mOriginalPrice >> mDiscountPercent >> mSize >> mManufacturer;
    cin.ignore();
}

void Product::Print() const
{
    int finalPrice = mOriginalPrice * (100 - mDiscountPercent) / 100;
    cout.width(5);
    cout << right << finalPrice << " ";

    char discountStr[8];
    sprintf(discountStr, "(%3d%%)", -mDiscountPercent);
    cout.width(8);
    cout << left << discountStr;
    cout.width(20);
    cout << left << mName;
    cout.width(6);
    cout << right << mSize << " " << mManufacturer << endl;
}