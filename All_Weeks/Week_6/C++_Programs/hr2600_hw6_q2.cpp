#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol)
{
    for (int i = 1; i <= n; i++)
    {
        cout << string(m + n - i, ' ') << string(2 * i - 1, symbol) << endl;
    }
}

void printPineTree(int n, char symbol)
{
    for (int i = 2; i <= n + 1; i++)
    {
        printShiftedTriangle(i, n - i + 1, symbol);
    }
}

int main()
{

    printPineTree(3, '#');
    return 0;
}
