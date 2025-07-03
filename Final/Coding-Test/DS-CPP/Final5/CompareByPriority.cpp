#include "CompareByPriority.h"

bool CompareByPriority::operator()(const Task& a, const Task& b) const
{
    return a.mPriority < b.mPriority;
}
