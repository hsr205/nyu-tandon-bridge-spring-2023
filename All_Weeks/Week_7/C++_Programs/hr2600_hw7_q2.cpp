#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> analyzeDividors(int num, int &outCountDivs, int &outSumDivs)
{

    vector<int> result;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            result.push_back(i);
        }
    }

    return result;
}

int getUserInput()
{

    int inputValue;

    cout << "Please enter an integer greater than 2: " << endl;
    cin >> inputValue;

    while (inputValue < 2)
    {
        cout << "That value is not greater than 2." << endl;
        cout << "Please enter an integer greater than 2: " << endl;
        cin >> inputValue;
    }

    return inputValue;
}

bool isPerfect(int iterableNum, int sumValue)
{

    if (iterableNum == sumValue)
    {
        return 1;
    }

    return 0;
}

void getResult()
{
    int inputValue = getUserInput();

    int outSumDivs1 = 0;
    int outSumDivs2 = 0;
    int outCountDivs1 = 0;
    int outCountDivs2 = 0;

    for (int i = 2; i <= inputValue; i++)
    {

        vector<int> resultVector1 = analyzeDividors(i, outCountDivs1, outSumDivs1);
        int sum1 = accumulate(resultVector1.begin(), resultVector1.end(), 0);

        vector<int> resultVector2 = analyzeDividors(sum1, outCountDivs2, outSumDivs2);
        int sum2 = accumulate(resultVector2.begin(), resultVector2.end(), 0);

        if (isPerfect(i, sum1))
        {
            cout << i << " is a perfect number." << endl;
        }

        else if (i == sum2)
        {
            cout << "The integers " << i << " and " << sum1 << " are amicable." << endl;
        }
    }
}

int main()
{

    getResult();
    return 0;
}
