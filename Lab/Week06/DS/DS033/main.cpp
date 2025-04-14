#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "CouponStack.h"

using namespace std;

int main()
{
    int stackSize;
    cin >> stackSize;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    CouponStack stack(stackSize);
    stack.Initialize();

    while (true)
    {
        string commandLine;
        if (!getline(cin, commandLine))
        {
            break;
        }

        if (commandLine.empty())
        {
            continue;
        }

        istringstream iss(commandLine);
        char cmd;
        iss >> cmd;

        if (!iss)
        {
            continue;
        }

        if (cmd == '+')
        {
            int rank;
            iss >> rank;

            string item;
            getline(iss, item);

            if (!item.empty() && item[0] == ' ')
            {
                item.erase(0, 1);
            }

            Coupon coupon{ rank, item };
            stack.Push(coupon);
        }
        else if (cmd == '-')
        {
            Coupon coupon = stack.Pop();
            if (coupon.Rank != -1 || coupon.Item != "")
            {
                cout << coupon.Rank << "등 -> " << coupon.Item << endl;
            }
        }
        else if (cmd == 'q')
        {
            break;
        }
        else
        {
            cout << "Please enter one of '+', '-', or 'q'." << endl;
        }
    }

    return 0;
}
