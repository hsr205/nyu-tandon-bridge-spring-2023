#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    int inputValue = 0;
    int firstDigit = 0;
    int lastDigit = 0;
    int totalPerfectSquares = 0;
    int totalPerfectNums = 0;

    int cnt = 0;

    cout << "Please enter a sequence of integers (with at least 1-digit and at most 9- digits)";
    cout << ", each one in a separate line. End your sequence by typing -1: " << endl;

    while (true)
    {

        cin >> inputValue;

        if (inputValue == -1)
        {
            break;
        }

        while (inputValue > 0)
        {

            int digit = inputValue % 10;

            inputValue /= 10;
            cnt++;


            if (cnt == 1)
            {
                firstDigit = digit;
            }
            if (inputValue <= 0)
            {
                lastDigit = digit;
            }

            if (firstDigit == sqrt(firstDigit * lastDigit) && lastDigit == sqrt(firstDigit * lastDigit) && firstDigit == lastDigit)
            {
                totalPerfectSquares++;
            }

            if ((firstDigit + lastDigit) % (firstDigit + lastDigit) == 0)
            {
                totalPerfectNums++;
            }
        }

        cnt = 0;
    }

    cout << "Total count of Perfect Squares in the given sequence: " << totalPerfectSquares << endl;
    cout << "Total count of Perfect Numbers in the given sequence: " << totalPerfectNums << endl;

    return 0;
}
