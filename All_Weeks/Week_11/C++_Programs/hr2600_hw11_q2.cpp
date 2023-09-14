#include <iostream>
#include <cmath>

using namespace std;

int const ARRAY_SIZE = 4;

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << "arr[i]: " << arr[i] << endl;
    }
}

// int sumOfSquares(int arr[], int arrSize)
// {

//     for (int i = 0; i < arrSize; i++)
//     {
//         arr[i] = pow(arr[i], 2);
//     }

//     printArray(arr, arrSize);

//     return 0;
// }

// TODO: Redo this
int sumOfSquares(int arr[], int arrSize)
{
    if (arrSize == 0)
    {
        return 0;
    }
    else
    {

        int currentElement = arr[arrSize - 1];
        int square = currentElement * currentElement;
        int sum = square + sumOfSquares(arr, arrSize - 1);
        return sum;
    }
}

int main()
{

    int arr[ARRAY_SIZE] = {2, -1, 3, 10};

    // sumOfSquares(arr, ARRAY_SIZE);

    // int result = sumOfSquares(arr, ARRAY_SIZE);

    cout << "result: " << sumOfSquares(arr, ARRAY_SIZE) << endl;
    // sumOfSquares(arr, ARRAY_SIZE);
    return 0;
}
