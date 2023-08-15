#include <iostream>

using namespace std;

int getFactorial(int inputInt);
int getFactorialEquationResult(int n, int k);
void getKCombinations();

void getNumDigits(int &numDigits);
void getDigitSum(int &digitSum);
void getDigitResult();

int main()
{

    getDigitResult();
    return 0;
}

void getDigitResult()
{
    int inputInt;
    int numDigits = inputInt;
    int digitSum = inputInt;
    cout << "Please enter a positive integer: " << endl;
    cin >> inputInt;

    getNumDigits(numDigits);
    getDigitSum(digitSum);

    cout << inputInt << " has " << numDigits << " digits and their sum is " << digitSum << endl;
}

void getDigitSum(int &digitSum)
{

    int result = 0;

    while (digitSum > 0)
    {
        int digit = digitSum % 10;
        result += digit;
        digitSum /= 10;
    }

    digitSum = result;
}

void getNumDigits(int &numDigits)
{

    int result = 0;

    while (numDigits > 0)
    {
        result++;
        numDigits /= 10;
    }

    numDigits = result;
}

void getKCombinations()
{

    int n;
    int k;
    cout << "Please enter n and k (k <= n)" << endl;
    cin >> n;
    cin >> k;

    int result = getFactorialEquationResult(n, k);

    cout << n << " choose " << k << " is " << result << endl;
}

int getFactorialEquationResult(int n, int k)
{
    int nFactorial = getFactorial(n);
    int kFactorial = getFactorial(k);
    int nMinusKFactorial = getFactorial(n - k);

    int numerator = nFactorial;
    int denominator = kFactorial * nMinusKFactorial;

    int result = numerator / denominator;

    return result;
}

int getFactorial(int inputInt)
{

    int result = 1;

    for (int i = 1; i <= inputInt; i++)
    {
        result *= i;
    }

    return result;
}
