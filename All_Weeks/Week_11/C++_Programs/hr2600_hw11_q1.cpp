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

int main()
{
    getTriangleResult();
    return 0;
}
