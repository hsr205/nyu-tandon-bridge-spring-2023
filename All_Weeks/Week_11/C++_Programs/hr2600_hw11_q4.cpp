#include <iostream>

using namespace std;

int const ARRAY_SIZE = 6;

int getLeastCost(int arr[], int arraySize)
{

    int sum = 0;

    for (int i = 1; i < arraySize; i++)
    {

        for (int j = 2; j < i + 1; j++)
        {
            // cout << "arr[j]:" << arr[j] << endl;

            if (arr[i] + arr[j] > arr[i] + arr[j + 1])
            {
                sum += arr[i] + arr[j + 1];
            }
            else
            {
                sum = arr[i] + arr[j];
            }
        }

        //     cout << "arr[i]: " << arr[i] << endl;
        //     cout << "arr[i+1]: " << arr[i + 1] << endl;

        //     if (arr[i] + arr[i + 3] > arr[i] + arr[i + 4])
        //     {
        //         sum = arr[i] + arr[i + 4];
        //     }
        //     else
        //     {
        //         sum = arr[i] + arr[i + 3];
        //     }
    }

    cout << "The sum is: " << sum << endl;

    return 0;
}

int main()
{

    int arr[ARRAY_SIZE] = {0, 3, 80, 6, 57, 10};

    getLeastCost(arr, ARRAY_SIZE);

    return 0;
}
