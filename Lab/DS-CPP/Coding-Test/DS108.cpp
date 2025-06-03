#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int size;
    cin >> size;

    vector<int> numbers(size);
    for (int index = 0; index < size; ++index)
    {
        cin >> numbers[index];
    }

    int candidate = numbers[0];
    int count = 1;

    for (int index = 1; index < size; ++index)
    {
        if (numbers[index] == candidate)
        {
            ++count;
        }
        else
        {
            --count;
            if (count == 0)
            {
                candidate = numbers[index];
                count = 1;
            }
        }
    }

    cout << candidate << endl;

    return 0;
}