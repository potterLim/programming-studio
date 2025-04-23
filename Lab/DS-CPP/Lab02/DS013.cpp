#include <iostream>
#include <string>

using namespace std;

struct Menu
{
    string MenuName;
    int Price;
};

struct Cafe
{
    string CafeName;
    int MenuCount;
    Menu* MenuList;
};

void AddCafe(Cafe& cafeRef);
void AddMenu(Menu& menuRef);
void DisplayMenus(Cafe& cafeRef);

int main()
{
    Cafe cafe;
    AddCafe(cafe);

    for (int i = 0; i < cafe.MenuCount; ++i)
    {
        AddMenu(cafe.MenuList[i]);
    }

    DisplayMenus(cafe);
    delete[] cafe.MenuList;
    return 0;
}

void AddCafe(Cafe& cafeRef)
{
    getline(cin, cafeRef.CafeName);
    cin >> cafeRef.MenuCount;
    cin.ignore(1, '\n');
    cafeRef.MenuList = new Menu[cafeRef.MenuCount];
}

void AddMenu(Menu& menuRef)
{
    cin >> menuRef.MenuName >> menuRef.Price;
}

void DisplayMenus(Cafe& cafeRef)
{
    cout << "===== " << cafeRef.CafeName << " =====" << endl;
    for (int i = 0; i < cafeRef.MenuCount; ++i)
    {
        cout << cafeRef.MenuList[i].MenuName << " " << cafeRef.MenuList[i].Price << endl;
    }
    cout << "==================" << endl;
}
