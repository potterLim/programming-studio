#ifndef MY_CIRCULAR_STUDENT_QUEUE_H
#define MY_CIRCULAR_STUDENT_QUEUE_H

#include <iostream>
#include <string>

#define DEFAULT_CAPACITY (50)

struct StudentInfo
{
    float gpa;
    std::string name;
};

class MyCircularStudentQueue
{
public:
    MyCircularStudentQueue(int capacity = DEFAULT_CAPACITY);
    ~MyCircularStudentQueue();

    void Enqueue(const StudentInfo& student);
    void Dequeue();
    const StudentInfo& Front() const;
    int Size() const;
    bool IsEmpty() const;

private:
    const int mMaxSize;
    int mFront;
    int mRear;
    StudentInfo* mList;
};

#endif /* MY_CIRCULAR_STUDENT_QUEUE_H */
