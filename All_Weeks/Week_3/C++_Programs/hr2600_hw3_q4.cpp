#include <iostream>

using namespace std;

int main()
{

    const int FLOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;
    int result;

    double realNumberInput;
    int flagValue;

    cout << "Please enter a real number: ";
    cin >> realNumberInput;

    cout << "Choose your rounding method: " << endl;
    cout << "1. Floor round: " << endl;
    cout << "2. Ceiling round: " << endl;
    cout << "3. Round to the nearest whole number: " << endl;
    cin >> flagValue;

    switch (flagValue)
    {
    case 1:
        result = realNumberInput;
        cout << result << endl;
        break;
    case 2:
        result = realNumberInput += 1;
        cout << result << endl;
        break;
    case 3:
        result = realNumberInput += .5;
        cout << result << endl;
        break;
    }

    return 0;
}