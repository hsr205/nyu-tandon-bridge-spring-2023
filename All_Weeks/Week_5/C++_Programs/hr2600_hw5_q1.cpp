#include <iostream>

using namespace std;

int main()
{

    int inputValue;
    cout << "Please enter a positive integer: " << endl;
    cin >> inputValue;

    for (int i = 1; i <= inputValue; i++)
    {
        for (int j = 1; j <= inputValue; j++)
        {
            cout << j * i << "\t";
        }
        cout << endl;
    }
    return 0;
}