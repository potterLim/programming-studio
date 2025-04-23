#ifndef COUPONSTACK_H
#define COUPONSTACK_H

#include "Coupon.h"

class CouponStack
{
private:
    int mMaxSize;
    int mTop;
    Coupon* mList;

public:
    CouponStack(int size = 10);
    ~CouponStack();
    void Initialize();
    bool IsEmpty() const;
    bool IsFull() const;
    void Push(const Coupon& elem);
    Coupon Pop();
    void Print() const;
    void RPrint();
};

#endif /* COUPONSTACK_H */