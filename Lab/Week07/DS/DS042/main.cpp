#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "MyLinkedStack.h"

using namespace std;

int main()
{
    ifstream fin("Data/input.txt");
    if (!fin.is_open())
    {
        cerr << "Error: Cannot open input file." << endl;
        return 1;
    }

    string line;
    while (getline(fin, line))
    {
        if (line.empty())
        {
            continue;
        }

        istringstream iss(line);
        vector<string> tokens;
        string token;
        while (iss >> token)
        {
            tokens.push_back(token);
        }

        int idx = 0;
        int tokenCount = static_cast<int>(tokens.size());

        while (idx < tokenCount)
        {
            int start = idx;
            MyLinkedStack stack;
            bool hasError = false;
            string errorMessage;
            bool outputDone = false;

            for (int j = start; j < tokenCount; ++j)
            {
                const string& currentToken = tokens[j];

                if (currentToken == "=")
                {
                    if (!outputDone)
                    {
                        if (!hasError)
                        {
                            int nodeCount = stack.GetNodeCount();
                            if (nodeCount > 1)
                            {
                                hasError = true;
                                errorMessage = "=> Too many operands !!!";
                            }
                            else if (nodeCount == 0)
                            {
                                hasError = true;
                                errorMessage = "=> Expression error !!!";
                            }
                            else
                            {
                                for (int k = start; k <= j; ++k)
                                {
                                    cout << tokens[k] << (k < j ? " " : "");
                                }
                                cout << " " << stack.Top() << endl;
                                outputDone = true;
                            }
                        }
                        if (hasError)
                        {
                            for (int k = start; k <= j; ++k)
                            {
                                cout << tokens[k] << (k < j ? " " : "");
                            }
                            cout << endl << errorMessage << endl;
                            outputDone = true;
                        }
                    }
                    idx = j + 1;
                    break;
                }

                if (currentToken.size() > 1 && currentToken[0] == '#')
                {
                    if (!hasError)
                    {
                        bool ok = true;
                        for (int m = 1; m < static_cast<int>(currentToken.size()); ++m)
                        {
                            if (!isdigit(currentToken[m]))
                            {
                                ok = false;
                                break;
                            }
                        }
                        if (!ok)
                        {
                            hasError = true;
                            errorMessage = "=> Expression error !!!";
                        }
                        else
                        {
                            int value = stoi(currentToken.substr(1));
                            stack.Push(value);
                        }
                    }
                }
                else if (currentToken == "+" || currentToken == "-" || currentToken == "*" || currentToken == "/" || currentToken == "%")
                {
                    if (!hasError)
                    {
                        if (stack.GetNodeCount() < 2)
                        {
                            hasError = true;
                            errorMessage = "=> Expression error !!!";
                        }
                        else
                        {
                            int b = stack.Top();
                            stack.Pop();
                            int a = stack.Top();
                            stack.Pop();

                            if ((currentToken == "/" || currentToken == "%") && b == 0)
                            {
                                for (int k = start; k <= j; ++k)
                                {
                                    cout << tokens[k] << (k < j ? " " : "");
                                }
                                cout << endl << "=> Division by 0" << endl;
                                outputDone = true;
                                idx = j + 1;
                                break;
                            }

                            int result;
                            if (currentToken == "+")
                            {
                                result = a + b;
                            }
                            else if (currentToken == "-")
                            {
                                result = a - b;
                            }
                            else if (currentToken == "*")
                            {
                                result = a * b;
                            }
                            else if (currentToken == "/")
                            {
                                result = a / b;
                            }
                            else
                            {
                                result = a % b;
                            }
                            stack.Push(result);
                        }
                    }
                }
                else
                {
                    if (!hasError)
                    {
                        hasError = true;
                        errorMessage = "=> Expression error !!!";
                    }
                }

                if (j == tokenCount - 1 && !outputDone)
                {
                    for (int k = start; k <= j; ++k)
                    {
                        cout << tokens[k] << (k < j ? " " : "");
                    }
                    cout << endl << "=> Expression error !!!" << endl;
                    idx = tokenCount;
                    outputDone = true;
                }
            }
        }
    }

    return 0;
}