#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int printTriangle(int n)
{
    int recursiveValue = 0;
    if (n == 0)
    {
        return n;
    }
    else
    {
        recursiveValue = printTriangle(n - 1) + 1;
        for (int i = 0; i < recursiveValue; i++)
        {
            cout << "*";
        }
        cout << endl;
        return recursiveValue;
    }
}

void printFlippedTriangle(int n)
{
    if (n != 0)
    {
        for (int i = n; i > 0; i--)
        {
            cout << "*";
        }
        cout << endl;
        printFlippedTriangle(n - 1);
    }
}

void printOppositeTriangles(int n)
{
    printFlippedTriangle(n);
    printTriangle(n);
}

void getTriangleResult()
{
    int n;
    cout << "Please enter an integer greater than 0:" << endl;
    cin >> n;

    cout << endl;

    cout << "Testing printTriangle() method: " << endl;
    cout << "----------------------------------------" << endl;
    printTriangle(n);
    cout << "----------------------------------------" << endl;
    cout << endl;

    cout << "Testing printOppositeTriangles() method: " << endl;
    cout << "----------------------------------------" << endl;
    printOppositeTriangles(n);
    cout << "----------------------------------------" << endl;
}

void printRuler(int n)
{
    /*

        What the question is asking for is the following:

        (1) If half of "n^2" then print out "n" number of "-"
        (2) If "n^2" / "n" can have a simplified fraction then print out either n/2 or n-1 number of "-"
        (3) Else print out a single "-"
    
    */
    if (n != 0)
    {
        int powerValue = pow(n, 2);
        // cout << "powerValue: " << powerValue << endl;
        // cout << "n: " << n << endl;
        if (powerValue / n == n)
        {
            cout << string(n,'-');
        }
        // cout << endl;
        // cout << "pow(n,2) - 1: " << pow(n,2) - 1 << endl;
        printRuler(n - 1);
    }
}

int main()
{
    printRuler(2);
    return 0;
}
