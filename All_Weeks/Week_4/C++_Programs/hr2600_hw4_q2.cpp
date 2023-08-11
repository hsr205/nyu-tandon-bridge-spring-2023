#include <iostream>

using namespace std;

int main()
{

    string result;
    int inputInt;
    cout << "Enter decimal number: " << endl;
    cin >> inputInt;

    int newInt = inputInt;

    while (newInt >= 1000)
    {
        newInt -= 1000;
        result += "M";
    }
    while (newInt >= 500)
    {
        newInt -= 500;
        result += "D";
    }
    while (newInt >= 100)
    {
        newInt -= 100;
        result += "C";
    }
    while (newInt >= 50)
    {
        newInt -= 50;
        result += "L";
    }
    while (newInt >= 10)
    {
        newInt -= 10;
        result += "X";
    }
    while (newInt >= 5)
    {
        newInt -= 5;
        result += "V";
    }
    while (newInt >= 1)
    {
        newInt -= 1;
        result += "I";
    }
    cout << inputInt << " is " << result << endl;
    return 0;
}