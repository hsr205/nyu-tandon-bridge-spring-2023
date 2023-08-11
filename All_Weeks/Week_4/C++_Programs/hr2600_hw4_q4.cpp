#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Question 4 - Section A:" << endl;
    int lengthOfSequence;
    int inputInt;
    int product = 1;
    int cnt = 0;

    cout << "Please enter the length of the sequence: ";
    cin >> lengthOfSequence;

    while (lengthOfSequence > cnt)
    {
        cin >> inputInt;
        product = product * inputInt;
        cnt++;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    double result = cbrt(product);

    cout << "The geometric mean is: " << result << endl;
    cout << "-------------------------------------------" << endl;

    cout << endl;

    cout << "Question 4 - Section B:" << endl;
    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
    product = 1;

    while (inputInt)
    {
        cin >> inputInt;
        if (inputInt == -1)
        {
            break;
        }
        product *= inputInt;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    result = cbrt(product);

    cout << "The geometric mean is: " << result << endl;

    return 0;
}