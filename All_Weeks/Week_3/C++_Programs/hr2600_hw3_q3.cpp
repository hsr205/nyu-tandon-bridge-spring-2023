#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int num1;
    int num2;
    int num3;

    cout << "Please enter value of a: ";
    cin >> num1;

    cout << "Please enter value of b: ";
    cin >> num2;

    cout << "Please enter value of c: ";
    cin >> num3;

    double equationResult = pow(num2, 2) - 4 * num1 * num3;

    bool isInfiniteSolution = num1 == 0 && num2 == 0 && num3 == 0;

    if (isInfiniteSolution)
    {
        cout << "Inifinite number of solutions." << endl;
    }

    else if (equationResult < 0)
    {
        cout << "No real solution." << endl;
    }
    else
    {
        double x1Result;
        double x2Result;
        x1Result = equationResult / (2 * num1);
        x2Result = equationResult / (2 * num1);

        if (x1Result == x2Result)
        {
            cout << "One real solution: " << x1Result << endl;
        }
        else
        {
            cout << "Two real solutions: " << endl;
            cout << "Solution One: " << x1Result << endl;
            cout << "Solution Two: " << x2Result << endl;
        }
    }

    return 0;
}