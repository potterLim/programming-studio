#include "MyClassManager.h"
#include <fstream>

string kname[2] = { "A+~F", "P/F" };

int main()
{
    int no;
    int quit = 0;
    string name;
    MyClassManager manager;
    manager.LoadData("Data/classes.txt");
    while (!quit)
    {
        cout << "\nMenu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n";
        cout << ">> Menu? > ";
        cin >> no;
        switch (no)
        {
        case 1:
            cout << "> 1.Class list (" << manager.GetCount() << " classes)\n";
            manager.PrintAllClasses();
            break;
        case 2:
            cout << "> 2.Add a Class\n";
            manager.AddClass();
            break;
        case 3:
            cout << "> 3.Modify a Class\n";
            manager.EditClass();
            break;
        case 4:
            cout << "> 4.Search a Class\n";
            cout << ">> Enter class name > ";
            cin >> name;
            manager.FindClasses(name);
            break;
        case 5:
            cout << "> 5.Apply a class\n";
            manager.ApplyMyClass();
            break;
        case 6:
            cout << "> 6.My classes\n";
            manager.PrintMyClasses();
            break;
        case 7:
            cout << "> 7.Save\n";
            manager.SaveMyClasses("Data/my_classes.txt");
            cout << "\n> All my classes were saved to output/DS024_my_classes.txt.\n";
            manager.SaveAllClasses("Data/classes.txt");
            cout << "\n> All of class list were saved to output/DS024_classes.txt.\n";
            break;
        case 0:
            quit = 1;
            break;
        default:
            break;
        }
    }

    return 0;
}