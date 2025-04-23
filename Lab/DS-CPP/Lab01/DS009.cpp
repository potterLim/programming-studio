#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int findRoom(int occupancy[5]);
void printReport(string maleNames[10], int maleRooms[10], int maleCount, string femaleNames[10], int femaleRooms[10], int femaleCount);

int main()
{
    string maleNames[10];
    string femaleNames[10];
    int maleRooms[10];
    int femaleRooms[10];
    int roomOccupancy[2][5] = {0};
    int maleCount = 0, femaleCount = 0;
    int menu;

    srand(time(0));
    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 프로그램" << endl;
    cout << "===========================================" << endl;
    while (1)
    {
        cout << "메뉴 : 1.남학생 등록 2.여학생 등록 0.종료 > ";
        cin >> menu;
        if (menu == 0)
        {
            break;
        }
        else if (menu == 1)
        {
            if (maleCount >= 10)
            {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> maleNames[maleCount];
            int roomNo = findRoom(roomOccupancy[0]);
            maleRooms[maleCount] = 100 + roomNo;
            cout << maleNames[maleCount] << " 학생 " << maleRooms[maleCount] << "호실 배정되었습니다." << endl;
            ++maleCount;
        }
        else if (menu == 2)
        {
            if (femaleCount >= 10)
            {
                cout << "정원 초과입니다. 등록불가!" << endl;
                continue;
            }
            cout << "학생 이름은? > ";
            cin >> femaleNames[femaleCount];
            int roomNo = findRoom(roomOccupancy[1]);
            femaleRooms[femaleCount] = 200 + roomNo;
            cout << femaleNames[femaleCount] << " 학생 " << femaleRooms[femaleCount] << "호실 배정되었습니다." << endl;
            ++femaleCount;
        }
    }
    cout << "===========================================" << endl;
    cout << "생활관 호실 배정 결과는 다음과 같습니다." << endl;
    cout << "===========================================" << endl;
    printReport(maleNames, maleRooms, maleCount, femaleNames, femaleRooms, femaleCount);

    return 0;
}

int findRoom(int occupancy[5])
{
    int available[5];
    int count = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (occupancy[i] < 2)
        {
            available[count++] = i;
        }
    }

    if (count == 0)
    {
        return -1;
    }

    int randIndex = rand() % count;
    int chosen = available[randIndex];
    occupancy[chosen]++;

    return chosen + 1;
}

void printReport(string maleNames[10], int maleRooms[10], int maleCount, string femaleNames[10], int femaleRooms[10], int femaleCount)
{
    cout << "남학생 명단 (" << maleCount << "명)" << endl;
    for (int i = 0; i < maleCount; ++i)
    {
        cout << i + 1 << ". " << maleNames[i] << " [" << maleRooms[i] << "호]" << endl;
    }
    cout << endl;
    cout << "여학생 명단 (" << femaleCount << "명)" << endl;
    for (int i = 0; i < femaleCount; ++i)
    {
        cout << i + 1 << ". " << femaleNames[i] << " [" << femaleRooms[i] << "호]" << endl;
    }
    cout << endl;
    cout << "호실별 배정 명단" << endl;
    for (int room = 101; room <= 105; ++room)
    {
        cout << room << "호 : ";
        bool first = true;
        for (int i = 0; i < maleCount; ++i)
        {
            if (maleRooms[i] == room)
            {
                if (!first)
                {
                    cout << " ";
                }
                cout << maleNames[i];
                first = false;
            }
        }
        cout << endl;
    }
    for (int room = 201; room <= 205; ++room)
    {
        cout << room << "호 : ";
        bool first = true;
        for (int i = 0; i < femaleCount; ++i)
        {
            if (femaleRooms[i] == room)
            {
                if (!first)
                {
                    cout << " ";
                }
                cout << femaleNames[i];
                first = false;
            }
        }
        cout << endl;
    }
}
