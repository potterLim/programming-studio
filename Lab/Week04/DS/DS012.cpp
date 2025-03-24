#include <iostream>
#include <string>

using namespace std;

struct Product
{
    string ProductName;
    int Price;
    string Manufacturer;
};

string ToLowerStr(const string& inputStr);
bool IsSame(const Product& productA, const Product& productB);

int main()
{
    Product firstProduct;
    Product secondProduct;

    cin >> firstProduct.ProductName >> firstProduct.Price >> firstProduct.Manufacturer;
    cin >> secondProduct.ProductName >> secondProduct.Price >> secondProduct.Manufacturer;

    if (IsSame(firstProduct, secondProduct))
    {
        cout << firstProduct.ProductName << " is equal" << endl;
    }
    else
    {
        cout << firstProduct.ProductName << " and " << secondProduct.ProductName << " is not equal." << endl;
    }

    return 0;
}

string ToLowerStr(const string& inputStr)
{
    string resultStr = inputStr;
    for (int i = 0; i < static_cast<int>(resultStr.size()); ++i)
    {
        if (resultStr[i] >= 'A' && resultStr[i] <= 'Z')
        {
            resultStr[i] = resultStr[i] + ('a' - 'A');
        }
    }
    return resultStr;
}

bool IsSame(const Product& productA, const Product& productB)
{
    if (ToLowerStr(productA.ProductName) == ToLowerStr(productB.ProductName)
        && productA.Price == productB.Price)
    {
        return true;
    }
    else
    {
        return false;
    }
}
