#include <iostream>

using namespace std;

const string ASTERICK = "*";
const string SPACE = " ";

int main()
{

    int inputInteger;
    cout << "Please enter a positive integer: ";
    cin >> inputInteger;

    for (int i = 0; i < inputInteger; i++)
    {
        int spaceLength = i + 1;
        int astericksLength = 2 * (inputInteger - i) - 1;

        for (int i = 0; i < astericksLength; i++)
        {
            cout << ASTERICK;
        }
        cout << endl;
        if (spaceLength == inputInteger)
        {
            break;
        }
        for (int k = 0; k < spaceLength; k++)
        {
            cout << SPACE;
        }
    }
    for (int i = inputInteger; i > 0; --i)
    {
        int spaceLength = i - 1;
        int astericksLength = 2 * (inputInteger - i) + 1;
        for (int k = 0; k < spaceLength; k++)
        {
            cout << SPACE;
        }
        for (int i = 0; i < astericksLength; i++)
        {
            cout << ASTERICK;
        }
        cout << endl;
    }
    return 0;
}