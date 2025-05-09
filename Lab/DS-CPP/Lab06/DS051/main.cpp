#include "MyCircularQueue.h"

using namespace std;

int main()
{
    MyCircularQueue queue;

    cout << "===== Dequeue x 1 =====" << endl;
    queue.Dequeue();
    queue.PrintDetail();

    cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
    for (int i = 0; i < 7; ++i)
    {
        queue.Enqueue((i + 1) * 10);
    }
    queue.PrintDetail();

    cout << "===== Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; ++i)
    {
        queue.Dequeue();
    }
    queue.PrintDetail();

    cout << "===== Enqueue x 6 (10 ~ 60) =====" << endl;
    for (int i = 0; i < 6; ++i)
    {
        queue.Enqueue((i + 1) * 10);
    }
    queue.PrintDetail();

    return 0;
}
