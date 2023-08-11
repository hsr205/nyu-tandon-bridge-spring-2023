#include <iostream>

using namespace std;

int main()
{

    int inputValue;
    cout << "Please input a positive integer: ";
    cin >> inputValue;

    for (int i = 1; i < inputValue; i++)
    {

        int evenCounter = 0;
        int oddCounter = 0;
        int counter = i;

        while (counter > 0)
        {
            int digit = counter % 10;

            if (digit % 2 == 0)
            {
                evenCounter++;
            }
            else
            {
                oddCounter++;
            }
            counter /= 10;
        }
        if (evenCounter > oddCounter)
        {
            cout << i << endl;
        }
    }
    return 0;
}