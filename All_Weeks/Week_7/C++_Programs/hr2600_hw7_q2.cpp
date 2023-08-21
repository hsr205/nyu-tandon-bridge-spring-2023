#include <iostream>
#include <cmath>

using namespace std;

bool isPerfect(int num)
{

    int sum = 0;

    for (int i = 1; i < num; i++)
    {
        // if (num % i == 0)
        // {
        sum += i;
        if (sum == num)
        {
            return 1;
        }
        // }
    }

    return 0;
}

bool isAmicableNum(int originalNum, int sumOfDivisors)
{

    if (originalNum == sumOfDivisors)
    {
        return 1;
    }

    return 0;
}

void analyzeDividors(int num, int &outCountDivs, int &outSumDivs)
{

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            if (isPerfect(num))
            {
                // cout << num << endl;
                cout << "The integer " << num << " is a perfect number" << endl;
            }
            // cout << "i: " << i << endl;
            outCountDivs++;
            outSumDivs += i;
        }
    }

    if (isAmicableNum(num, outSumDivs))
    {
        cout << "The two integers: " << num << " and " << outSumDivs << " are amicable numbers." << endl;
    }
}

int main()
{
    int inputValue = 6;
    int outCountDivs = 0;
    int outSumDivs = 0;

    // bool isResult = isPerfect(inputValue);

    analyzeDividors(inputValue, outCountDivs, outSumDivs);

    // cout << "outCountDivs: " << outCountDivs << endl;
    // cout << "outSumDivs: " << outSumDivs << endl;

    return 0;
}
