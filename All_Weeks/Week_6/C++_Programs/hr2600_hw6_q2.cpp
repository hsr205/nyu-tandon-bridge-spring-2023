#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol)
{

    for (int i = 1; i < (n * 2); i++)
    {
        // TODO: Find way to center the symbols of the triangle

        if (i % 2 != 0)
        {
            cout << string(m, ' ') << string(i, symbol) << endl;
        }
    }
}

void printPineTree(int n, char symbol)
{

    for (int i = 1; i < (n + 1); i++)
    {
        printShiftedTriangle(n+i, 4 - i, symbol);
    }

}

int main()
{

    printShiftedTriangle(3, 4, '+');
    // printPineTree(3, '#');
    return 0;
}
