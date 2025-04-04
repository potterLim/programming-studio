#include <fstream>
#include <iostream>
#include <sstream>

#define MAX (50)

using namespace std;

string kname[2] = {"A+~F", "P/F"};

class MyClass
{
public:
    MyClass(int ncode, string nname, int nunit, int ngrading)
        : mCode(ncode), mName(nname), mUnit(nunit), mGrading(ngrading)
    {
    }
    ~MyClass() {}
    int GetCode() { return mCode; }
    string GetName() { return mName; }
    int GetUnit() { return mUnit; }
    int GetGrading() { return mGrading; }
    void SetCode(int newCode) { mCode = newCode; }
    void SetName(string newName) { mName = newName; }
    void SetUnit(int newUnit) { mUnit = newUnit; }
    void SetGrading(int newGrading) { mGrading = newGrading; }
    string ToString()
    {
        stringstream sstm;
        sstm << "[" << mCode << "] " << mName << " [credit " << mUnit << " - " + kname[mGrading - 1] << "]";
        return sstm.str();
    }
    string ToStringSave()
    {
        stringstream sstm;
        sstm << mCode << " " << mName << " " << mUnit << " " << mGrading;
        return sstm.str();
    }

private:
    int mCode;
    string mName;
    int mUnit;
    int mGrading;
};

class MyClassManager
{
public:
    MyClassManager() : mCount(0), mAppliedCount(0) {}
    ~MyClassManager() {}
    int GetCount() { return mCount; }
    int GetMyCount() { return mAppliedCount; }
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

int main()
{
    int no;
    int quit = 0;
    string name;
    MyClassManager manager;
    manager.LoadData("Data/DS024_classes.txt");
    while (!quit)
    {
        cout << "\nMenu 1.List 2.Add 3.Modify 4.Search 5.Apply 6.My classes 7.Save 0.Quit\n";
        cout << ">> Menu? > ";
        cin >> no;
        switch (no)
        {
        case 1:
        {
            cout << "> 1.Class list (" << manager.GetCount() << " classes)\n";
            manager.PrintAllClasses();
            break;
        }
        case 2:
        {
            cout << "> 2.Add a Class\n";
            manager.AddClass();
            break;
        }
        case 3:
        {
            cout << "> 3.Modify a Class\n";
            manager.EditClass();
            break;
        }
        case 4:
        {
            cout << "> 4.Search a Class\n";
            cout << ">> Enter class name > ";
            cin >> name;
            manager.FindClasses(name);
            break;
        }
        case 5:
        {
            cout << "> 5.Apply a class\n";
            manager.ApplyMyClass();
            break;
        }
        case 6:
        {
            cout << "> 6.My classes\n";
            manager.PrintMyClasses();
            break;
        }
        case 7:
        {
            cout << "> 7.Save\n";
            manager.SaveMyClasses("Data/DS024_my_classes.txt");
            cout << "\n> All my classes were saved to output/DS024_my_classes.txt.\n";
            manager.SaveAllClasses("Data/DS024_classes.txt");
            cout << "\n> All of class list were saved to output/DS024_classes.txt.\n";
            break;
        }
        case 0:
        {
            quit = 1;
            break;
        }
        default:
        {
            break;
        }
        }
    }
    return 0;
}

void MyClassManager::LoadData(string filename)
{
    string line, name;
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
        index = -1;
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
    file << "All : " << mAppliedCount << " classes, " << totalCredits << " credits (A+~F " << totalAF << " credits, P/F " << totalPF << " credits)\n";
    file.close();
}
