#include "MyClass.h"

MyClass::MyClass(int ncode, string nname, int nunit, int ngrading)
    : mCode(ncode)
    , mName(nname)
    , mUnit(nunit)
    , mGrading(ngrading)
{
}

int MyClass::GetCode()
{
    return mCode;
}

string MyClass::GetName()
{
    return mName;
}

int MyClass::GetUnit()
{
    return mUnit;
}

int MyClass::GetGrading()
{
    return mGrading;
}

void MyClass::SetCode(int newCode)
{
    mCode = newCode;
}

void MyClass::SetName(string newName)
{
    mName = newName;
}

void MyClass::SetUnit(int newUnit)
{
    mUnit = newUnit;
}

void MyClass::SetGrading(int newGrading)
{
    mGrading = newGrading;
}

string MyClass::ToString()
{
    stringstream sstm;
    sstm << "[" << mCode << "] " << mName << " [credit " << mUnit << " - " + kname[mGrading - 1] << "]";
    return sstm.str();
}

string MyClass::ToStringSave()
{
    stringstream sstm;
    sstm << mCode << " " << mName << " " << mUnit << " " << mGrading;
    return sstm.str();
}