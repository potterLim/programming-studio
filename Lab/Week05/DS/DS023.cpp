#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Product
{
public:
    Product() : mOriginalPrice(0), mDiscountPercent(0) {}
    void Input()
    {
        cin.ignore();
        getline(cin, mName);
        cin >> mOriginalPrice >> mDiscountPercent >> mSize >> mManufacturer;
        cin.ignore();
    }
    void Print() const
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

private:
    string mName;
    int mOriginalPrice;
    int mDiscountPercent;
    string mSize;
    string mManufacturer;
};

int main()
{
    const int MAX_PRODUCTS = 100;
    Product* products[MAX_PRODUCTS];
    int count = 0;
    while (true)
    {
        int menu;
        cout << "1. Add  2. List  3. Quit > ";
        cin >> menu;
        if (menu == 1)
        {
            if (count >= MAX_PRODUCTS)
            {
                cout << "더 이상 상품을 추가할 수 없습니다." << endl;
                continue;
            }
            products[count] = new Product();
            products[count]->Input();
            ++count;
        }
        else if (menu == 2)
        {
            for (int i = 0; i < count; ++i)
            {
                products[i]->Print();
            }
        }
        else if (menu == 3)
        {
            break;
        }
        else
        {
            cout << "잘못된 메뉴입니다." << endl;
        }
    }
    for (int i = 0; i < count; ++i)
    {
        delete products[i];
    }
    return 0;
}
