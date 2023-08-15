#include <iostream>

using namespace std;

int fib(int num)
{

    int currentValue = 1;
    int previousValue = 1;
    int total = 0;

    if (num == 1 || num == 2)
    {
        return 1;
    }

    for (int i = 1; i < (num - 1); i++)
    {

        total = currentValue + previousValue;
        previousValue = currentValue;
        currentValue = total;

        if (i == (num - 2))
        {
            return total;
        }
    }

    return 0;
}

int main()
{

    int inputInt;
    cout << "Please enter a positive integer: ";
    cin >> inputInt;
    cout << fib(inputInt) << endl;

    return 0;
}
