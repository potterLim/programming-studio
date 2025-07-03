#ifndef TASK_H
#define TASK_H

#include <string>

class Task
{
public:
    Task(const std::string& name, int priority);

    std::string mName;
    int mPriority;
};

#endif /* TASK_H */
