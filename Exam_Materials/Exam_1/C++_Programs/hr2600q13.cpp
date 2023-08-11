#include <iostream>

using namespace std;

int main()
{

    int inputValue;

    cout << "Please enter a positive integer: " << endl;
    cin >> inputValue;

    // // Top of Pyramid
    for (int i = 1; i < (2 * inputValue); i++)
    {
        if (i == inputValue + 2)
        {
            break;
        }

        for (int j = (inputValue - i); j >= 0; j--)
        {
            cout << " ";
        }
        for (int j = 1; j < (i * 2); j++)
        {
            cout << "*";
        }

        cout << endl;
    }

    // Bottom of Pyramid
    // for (int i = 1; i < (2 * inputValue); i++)
    // {
    //     // if (i == inputValue)
    //     // {
    //     //     break;
    //     // }

    //     for (int j = 0; j < (inputValue - i); j++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = i; j < (inputValue * 2); j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    return 0;
}
