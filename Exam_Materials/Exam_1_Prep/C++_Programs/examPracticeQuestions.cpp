#include <iostream>
#include <string>

using namespace std;

void printSideWaysPyramid()
{
    int size = 3;

    // cout << "Please enter a positive integer: " << endl;
    // cin >> size;

    int tempValue = size * 3;

    // Top of Pyramid
    for (int i = 1; i < tempValue; i++)
    {
        if (i == tempValue - 1)
        {
            break;
        }

        for (int j = tempValue - 1; j > i; j--)
        {
            cout << " ";
        }

        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i < tempValue; i++)
    {
        for (int j = 1; j < i; j++)
        {
            cout << " ";
        }

        for (int j = i; j < tempValue; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void getGroupTotals()
{

    int cnt = 0;
    int inputNum = 0;
    int groupTotalOne = 0;
    int groupTotalTwo = 0;
    int groupTotalThree = 0;
    int groupTotalFour = 0;

    int digit = 0;
    int firstDigit = 0;
    int lastDigit = 0;

    cout << "Please enter a sequence of numbers: " << endl;

    while (true)
    {
        cin >> inputNum;
        if (inputNum == -1)
        {
            break;
        }

        while (inputNum > 0)
        {
            int digit = inputNum % 10;
            inputNum /= 10;
            cnt++;

            if (cnt == 1)
            {
                firstDigit = digit;
            }

            if (inputNum <= 0)
            {
                lastDigit = digit;

                if (firstDigit + lastDigit < 5)
                {
                    groupTotalOne++;
                }
                else if ((firstDigit + lastDigit >= 5) && (firstDigit + lastDigit) < 10)
                {
                    groupTotalTwo++;
                }
                else if ((firstDigit + lastDigit >= 10) && (firstDigit + lastDigit) < 15)
                {
                    groupTotalThree++;
                }
                else if (firstDigit + lastDigit >= 15)
                {
                    groupTotalFour++;
                }
            }
        }

        cnt = 0;
    }

    cout << endl;

    cout << "Total count of numbers in the Numbers Group 1: " << groupTotalOne << endl;
    cout << "Total count of numbers in the Numbers Group 2: " << groupTotalTwo << endl;
    cout << "Total count of numbers in the Numbers Group 3: " << groupTotalThree << endl;
    cout << "Total count of numbers in the Numbers Group 4: " << groupTotalFour << endl;
}

int main()
{

    int n;

    cout << "Please enter a positive integer: " << endl;
    cin >> n;

    for (int i = 1; i <= (2 * n); i++)
    {
        for (int j = i; j < (2 * n); j++)
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
