#include <iostream>

using namespace std;

int main()
{
    int base = 1;
    int result = 0;
    int decimalValue;
    int remainderValue;

    cout << "Enter decimal number: " << endl;
    cin >> decimalValue;
    int initialValue = decimalValue;

    while (decimalValue > 0)
    {
        remainderValue = decimalValue % 2;
        result += remainderValue * base;
        decimalValue /= 2;
        base *= 10;
    }

    cout << "The binary representation of " << initialValue << " is " << result << endl;
    return 0;
}