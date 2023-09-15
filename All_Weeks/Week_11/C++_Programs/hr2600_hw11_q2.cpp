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

// TODO: Redo this to fiully understand
int sumOfSquares(int arr[], int arrSize)
{
    if (arrSize == 0)
    {
        return 0;
    }
    else
    {

        int currentElement = arr[arrSize - 1];
        // cout << "currentElement: " << currentElement << endl;
        // sumOfSquares(arr, arrSize - 1);
        int square = pow(currentElement, 2);
        // cout << "square: " << square << endl;
        int sum = square + sumOfSquares(arr, arrSize - 1);
        // cout << "sum: " << sum << endl;
        return sum;
    }
}

// int addDigits(int *arr, int arrSize)
// {

//     if (arrSize == 1)
//     {
//         return arr[0];
//     }
//     else
//     {
//         int temp;
//         temp = addDigits(arr, arrSize - 1);
//         return temp + arr[arrSize - 1];
//     }
// }

// int getPowOf(int a, int n)
// {

//     if (n == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         int temp;
//         temp = getPowOf(a, n - 1) * a;
//         return temp;
//     }
// }

bool isSortedNonRecursive(int arr[], int arrSize)
{
    bool result = false;

    for (int i = 0; i < arrSize - 1; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            result = true;
        }
        else
        {
            return 0;
        }
    }

    return result;
}

bool isSorted(int arr[], int arrSize)
{
    bool result = false;

    if (arrSize == 0)
    {
        // cout << "Inside Conditional: " << endl;
        // cout << "arr[arrSize]: " << arr[arrSize-1] << endl;
        // result = arr[arrSize - 1] >= arr[arrSize - 2];

        return result;
    }
    else
    {
        // cout << "arr[arrSize]: " << arr[arrSize] << endl;
        cout << "arr[arrSize-1]: " << arr[arrSize-1] << endl;
        cout << "arr[arrSize-2]: " << arr[arrSize-2] << endl;
        bool result = arr[arrSize - 1] >= arr[arrSize - 2];
        cout << "arr[arrSize - 1] >= arr[arrSize - 2]: " << result << endl;
        cout << "-----------------------------------------------------------" << endl;

        // result = arr[arrSize - 1] >= arr[arrSize - 2];
        // isSorted(arr, arrSize - 1);

        return isSorted(arr, arrSize - 1);
    }
}

int main()
{

    int arr[ARRAY_SIZE] = {2, -1, 3, 10};
    int arr2[ARRAY_SIZE] = {1, 2, 3, 4};

    // cout << "Is array sorted: " << isSortedNonRecursive(arr2, ARRAY_SIZE) << endl;

    isSorted(arr2, ARRAY_SIZE);

    cout << "Is array sorted: " << isSorted(arr2, ARRAY_SIZE) << endl;

    return 0;
}
