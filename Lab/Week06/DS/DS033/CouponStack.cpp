#include "CouponStack.h"
#include <iostream>

using namespace std;

CouponStack::CouponStack(int size) 
    : mMaxSize(size)
    , mTop(-1)
{
    mList = new Coupon[mMaxSize];
}

CouponStack::~CouponStack()
{
    delete[] mList;
}

void CouponStack::Initialize()
{
    mTop = -1;
}

bool CouponStack::IsEmpty() const
{
    return (mTop == -1);
}

bool CouponStack::IsFull() const
{
    return (mTop == mMaxSize - 1);
}

void CouponStack::Push(const Coupon& elem)
{
    if (IsFull())
    {
        cout << "Stack is full. Cannot push (" << elem.Rank << "등 " << elem.Item << ")" << endl;
        return;
    }

    mList[++mTop] = elem;
}

Coupon CouponStack::Pop()
{
    if (IsEmpty())
    {
        cout << "Stack is empty. Cannot pop." << endl;
        return Coupon{ -1, "" };
    }

    return mList[mTop--];
}

void CouponStack::Print() const
{
    if (IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    cout << "===== Stack Contents (top -> bottom) ======" << endl;
    for (int i = mTop; i >= 0; --i)
    {
        cout << mList[i].Rank << "등 " << mList[i].Item << endl;
    }
    cout << "===========================================" << endl;
}

void CouponStack::RPrint()
{
    if (IsEmpty())
    {
        cout << "(Stack is empty)" << endl;
        return;
    }

    cout << "===== Pop & Print =====" << endl;
    while (!IsEmpty())
    {
        Coupon c = Pop();
        cout << c.Rank << "등 " << c.Item << endl;
    }
    cout << "=======================" << endl;
}
