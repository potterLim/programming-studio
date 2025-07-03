#ifndef COMPARE_BY_PRIORITY_H
#define COMPARE_BY_PRIORITY_H

#include "Task.h"

class CompareByPriority
{
public:
    bool operator()(const Task& a, const Task& b) const;
};

#endif /* COMPARE_BY_PRIORITY_H */
