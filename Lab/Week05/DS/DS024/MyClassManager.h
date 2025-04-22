#ifndef MYCLASSMANAGER_H
#define MYCLASSMANAGER_H

#include "MyClass.h"

#define MAX (50)

class MyClassManager
{
public:
    MyClassManager();

    int GetCount();
    int GetMyCount();

    void LoadData(string filename);
    void PrintAllClasses();
    void FindClasses(string name);
    void SaveAllClasses(string filename);
    void AddClass();
    void EditClass();
    void ApplyMyClass();
    void PrintMyClasses();
    void SaveMyClasses(string filename);

private:
    MyClass* mAllClasses[MAX];
    MyClass* mMyClasses[10];
    int mCount;
    int mAppliedCount;
};

#endif /* MYCLASSMANAGER_H */
