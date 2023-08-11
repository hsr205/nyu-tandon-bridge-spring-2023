#include <iostream>

using namespace std;

int main()
{

    int inputInt;
    cout << "Question1 - Section A" << endl;
    cout << "Please enter a positive integer: ";
    cin >> inputInt;

    int upperLimit = inputInt * 2;

    while (inputInt >= 0)
    {

        for (int i = 2; i <= upperLimit; i += 2)
        {
            cout << i << endl;
        }

        break;
    }

    cout << "-----------------------------------" << endl;
    cout << endl;

    cout << "Question1 - Section B" << endl;
    cout << "Please enter a positive integer: ";
    cin >> inputInt;

    upperLimit = inputInt * 2;

    for (int i = 2; i <= upperLimit; i += 2)
    {
        cout << i << endl;
    }

    cout << "-----------------------------------" << endl;
    cout << endl;

    return 0;
}