#include <iostream>

using namespace std;

const int ARRAY_SIZE = 5;


int minArray1(int arr[], int arrSize)
{

    if (arrSize == 0)
    {

        return arr[0];
    }

    return min(arr[0], minArray1(arr + 1, arrSize - 1));
}

int main()
{
    int arr[ARRAY_SIZE] = {1, -100, 3, 4, -5};

    int result = minArray1(arr, ARRAY_SIZE);
    cout << "Min Value: " << result << endl;

    // minArray1(arr, ARRAY_SIZE);

    return 0;
}
