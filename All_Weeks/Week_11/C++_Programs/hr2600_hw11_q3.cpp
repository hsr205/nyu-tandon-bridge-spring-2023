#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;

int minInArray1(int arr[], int arrSize)
{

    if (arrSize == 0)
    {

        return arr[0];
    }

    return min(arr[0], minInArray1(arr + 1, arrSize - 1));
}

int minInArray2(int arr[], int low, int high)
{

    if (low == high)
    {

        return arr[low];
    }

    return min(arr[low], minInArray2(arr + 1, low, high - 1));
}

int main()
{
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl; // should both be -9

    cout << "--------------------------" << endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr + 2, 4);      // arr+2 is equivalent to &(arr[2])
    cout << res3 << " " << res4 << endl; // should both be 3

    return 0;
}
