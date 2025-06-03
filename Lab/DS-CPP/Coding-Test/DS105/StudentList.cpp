#include "StudentList.h"
#include <iostream>

using namespace std;

StudentList::StudentList()
    : mHead(nullptr)
    , mTail(nullptr)
{
}

StudentList::~StudentList()
{
    Clear();
}

void StudentList::AddStudent(int score, const std::string& name)
{
    StudentNode* newNode = new StudentNode(score, name);
    if (mHead == nullptr)
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        mTail->mNext = newNode;
        mTail = newNode;
    }
}

void StudentList::BubbleSortDescending()
{
    if (mHead == nullptr)
    {
        return;
    }

    bool swapped;
    do
    {
        swapped = false;
        StudentNode* current = mHead;
        while (current->mNext != nullptr)
        {
            if (current->mScore < current->mNext->mScore)
            {
                int tempScore = current->mScore;
                string tempName = current->mName;

                current->mScore = current->mNext->mScore;
                current->mName = current->mNext->mName;

                current->mNext->mScore = tempScore;
                current->mNext->mName = tempName;

                swapped = true;
            }
            current = current->mNext;
        }
    } while (swapped);
}

void StudentList::PrintList() const
{
    StudentNode* current = mHead;
    int rank = 1;

    while (current != nullptr)
    {
        cout << rank << "> " << current->mScore << " " << current->mName << endl;
        ++rank;
        current = current->mNext;
    }
}

void StudentList::Clear()
{
    StudentNode* current = mHead;
    while (current != nullptr)
    {
        StudentNode* temp = current;
        current = current->mNext;
        delete temp;
    }
    mHead = nullptr;
    mTail = nullptr;
}
