#include <iostream>

using namespace std;

double eApprox(int num)
{

    double result = 1;
    double eApproximation = 1;
    for (int i = 1; i <= num; i++)
    {
        result *= i;
        eApproximation += 1 / result;
    }

    return eApproximation;
}

int main()
{
    int n = 15;

    cout.precision(30);

    for (int n = 1; n <= 15; n++)
    {
        cout << "n = " << n << '\t' << eApprox(n) << endl;
    }

    return 0;
}
