#include <iostream>
#include <queue>
#include <string>

#include "Task.h"
#include "CompareByPriority.h"

using namespace std;

int main()
{
    cout << "Enter tasks as (name,priority) format: ";
    string input;
    getline(cin, input);

    priority_queue<Task, vector<Task>, CompareByPriority> taskQueue;

    size_t pos = 0;
    while ((pos = input.find('(')) != string::npos)
    {
        size_t end = input.find(')', pos);
        if (end == string::npos)
        {
            break;
        }

        string token = input.substr(pos + 1, end - pos - 1);
        size_t comma = token.find(',');

        if (comma != string::npos)
        {
            string name = token.substr(0, comma);
            int priority = stoi(token.substr(comma + 1));
            taskQueue.push(Task(name, priority));
        }

        input = input.substr(end + 1);
    }

    while (!taskQueue.empty())
    {
        cout << taskQueue.top().mName;
        taskQueue.pop();

        if (!taskQueue.empty())
        {
            cout << " → ";
        }
    }

    cout << endl;
    return 0;
}
