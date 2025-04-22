#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

extern string kname[2];

class MyClass
{
public:
    MyClass(int ncode, string nname, int nunit, int ngrading);

    int GetCode();
    string GetName();
    int GetUnit();
    int GetGrading();

    void SetCode(int newCode);
    void SetName(string newName);
    void SetUnit(int newUnit);
    void SetGrading(int newGrading);

    string ToString();
    string ToStringSave();

private:
    int mCode;
    string mName;
    int mUnit;
    int mGrading;
};

#endif // MYCLASS_H