#include <iostream>

using namespace std;

int findOddIntegersAndSum(int S[], int length, int &sumOdds)
{

    if (length == 0)
    {
        return 0;
    }

    int intValue = S[length - 1];

    if (intValue % 2 != 0)
    {
        sumOdds += intValue;
    }

    return sumOdds + findOddIntegersAndSum(S, length - 1, sumOdds);
}

int main()
{

    // cout << "Hello from: " << __FILE__ << endl;

    int sumOdds = 0;
    int S[] = {10, -5, -20, 0, 7, -15, -5, -100};
    int size = sizeof(S) / sizeof(S[0]);

    cout << "sumOdds: " << sumOdds << endl;

    findOddIntegersAndSum(S, size, sumOdds);

    cout << "sumOdds: " << sumOdds << endl;

    return 0;
}
