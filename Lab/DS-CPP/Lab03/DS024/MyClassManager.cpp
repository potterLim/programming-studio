#include "MyClassManager.h"
#include <fstream>

MyClassManager::MyClassManager()
    : mCount(0)
    , mAppliedCount(0)
{
}

int MyClassManager::GetCount()
{
    return mCount;
}

int MyClassManager::GetMyCount()
{
    return mAppliedCount;
}

void MyClassManager::LoadData(string filename)
{
    string name;
    int code;
    int unit;
    int grading;

    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file " << filename << endl;
        return;
    }

    while (file >> code >> name >> unit >> grading)
    {
        mAllClasses[mCount] = new MyClass(code, name, unit, grading);
        ++mCount;
    }

    file.close();
    cout << "> Load " << mCount << " classes.\n";
}

void MyClassManager::PrintAllClasses()
{
    for (int i = 0; i < mCount; ++i)
    {
        cout << mAllClasses[i]->ToString() << endl;
    }
}

void MyClassManager::SaveAllClasses(string filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Unable to open file " << filename << " for saving." << endl;
        return;
    }

    for (int i = 0; i < mCount; ++i)
    {
        file << mAllClasses[i]->ToStringSave();
        if (i < mCount - 1)
        {
            file << endl;
        }
    }

    file.close();
}

void MyClassManager::FindClasses(string name)
{
    int found = 0;
    cout << "Searching keyword: " << name << endl;

    for (int i = 0; i < mCount; ++i)
    {
        if (mAllClasses[i]->GetName().find(name) != string::npos)
        {
            cout << mAllClasses[i]->ToString() << endl;
            ++found;
        }
    }

    cout << found << " classes found.\n";
}

void MyClassManager::AddClass()
{
    string name;
    int code, unit, grading;

    while (true)
    {
        cout << ">> code number > ";
        cin >> code;
        bool duplicate = false;

        for (int i = 0; i < mCount; ++i)
        {
            if (mAllClasses[i]->GetCode() == code)
            {
                duplicate = true;
                cout << ">> Code duplicated! Retry.\n";
                break;
            }
        }

        if (!duplicate)
        {
            break;
        }
    }

    cout << ">> class name > ";
    cin >> name;
    cout << ">> credits > ";
    cin >> unit;
    cout << ">> grading (1: A+~F, 2: P/F) > ";
    cin >> grading;

    if (mCount < MAX)
    {
        mAllClasses[mCount] = new MyClass(code, name, unit, grading);
        ++mCount;
        cout << "Class added successfully.\n";
    }
    else
    {
        cout << "Error: Class list is full.\n";
    }
}

void MyClassManager::EditClass()
{
    int code;
    int index = -1;

    while (true)
    {
        cout << ">> Enter a code of class > ";
        cin >> code;

        for (int i = 0; i < mCount; ++i)
        {
            if (mAllClasses[i]->GetCode() == code)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            break;
        }

        cout << "> No such class.\n";
    }

    cout << "> Current: " << mAllClasses[index]->ToString() << endl;

    string newName;
    int newUnit, newGrading;

    cout << ">> Enter new class name > ";
    cin >> newName;
    cout << ">> Enter new credits > ";
    cin >> newUnit;
    cout << ">> Enter new grading (1:Grade, 2:P/F) > ";
    cin >> newGrading;

    mAllClasses[index]->SetName(newName);
    mAllClasses[index]->SetUnit(newUnit);
    mAllClasses[index]->SetGrading(newGrading);

    cout << "Modified.\n";
}

void MyClassManager::ApplyMyClass()
{
    while (true)
    {
        if (mAppliedCount >= 10)
        {
            cout << "Error: Cannot apply more classes. Maximum limit reached.\n";
            break;
        }

        int code;
        cout << ">> Enter a class code > ";
        cin >> code;

        int idx = -1;
        for (int i = 0; i < mCount; ++i)
        {
            if (mAllClasses[i]->GetCode() == code)
            {
                idx = i;
                break;
            }
        }

        if (idx == -1)
        {
            cout << ">> No such code of class.\n";
            continue;
        }

        bool alreadyApplied = false;
        for (int i = 0; i < mAppliedCount; ++i)
        {
            if (mMyClasses[i]->GetCode() == code)
            {
                alreadyApplied = true;
                cout << "Error: Class already applied.\n";
                break;
            }
        }

        if (alreadyApplied)
        {
            continue;
        }

        mMyClasses[mAppliedCount] = mAllClasses[idx];
        ++mAppliedCount;

        cout << ">> " << mAllClasses[idx]->ToString() << endl;

        if (mAppliedCount >= 10)
        {
            cout << mAppliedCount << " classes has been applied.\n";
            break;
        }

        int choice;
        cout << ">> Add more?(1:Yes 2:No) > ";
        cin >> choice;

        if (choice == 2)
        {
            cout << mAppliedCount << " classes has been applied.\n";
            break;
        }
    }
}

void MyClassManager::PrintMyClasses()
{
    if (mAppliedCount == 0)
    {
        cout << "No classes applied.\n";
        return;
    }

    int totalCredits = 0;

    for (int i = 0; i < mAppliedCount; ++i)
    {
        cout << (i + 1) << ". " << mMyClasses[i]->ToString() << endl;
        totalCredits += mMyClasses[i]->GetUnit();
    }

    cout << "All : " << totalCredits << " credits" << endl;
}

void MyClassManager::SaveMyClasses(string filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        return;
    }

    file << "My Classes\n";

    int totalAF = 0;
    int totalPF = 0;
    int totalCredits = 0;

    for (int i = 0; i < mAppliedCount; ++i)
    {
        file << (i + 1) << ". " << mMyClasses[i]->ToString() << "\n";

        if (mMyClasses[i]->GetGrading() == 1)
        {
            totalAF += mMyClasses[i]->GetUnit();
        }
        else
        {
            totalPF += mMyClasses[i]->GetUnit();
        }

        totalCredits += mMyClasses[i]->GetUnit();
    }

    file << "All : " << mAppliedCount << " classes, " << totalCredits
        << " credits (A+~F " << totalAF << " credits, P/F " << totalPF << " credits)\n";
    file.close();
}
