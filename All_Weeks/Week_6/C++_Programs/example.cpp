#include <iostream>
#include <cmath>

using namespace std;

int getDivisorCount(int inputValue)
{

    int divisorCount = 0;

    for (int i = 0; i <= sqrt(inputValue); i++)
    {
        if (inputValue % i == 0)
        {
            divisorCount++;
        }
    }
    return divisorCount;
}

bool isPrime(int inputValue)
{
    int divisorCount = getDivisorCount(inputValue);

    if (divisorCount == 1)
    {
        return true;
    }

    return false;
}

int main()
{

    int inputValue = 100;

    for (int i = 3; i <= inputValue; i++)
    {

        if (isPrime(i))
        {
            cout << i << " is a prime number." << endl;
        }
        // else
        // {
        //     cout << i << " is not prime number." << endl;
        // }
    }

    return 0;
}
