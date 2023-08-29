#include <iostream>

using namespace std;

const int ARRAY_SIZE = 6;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{

    int resultArray[ARRAY_SIZE];

    for (int i = 0; i < arrSize; i++)
    {
        // cout << "arr[i]: " << arr[i] << endl;
        if (arr[i] > 0)
        {
            cout << "arr[i]: " << arr[i] << endl;
            resultArray[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

    return resultArray;
}

int main()
{

    int outPosArrSize = 0;
    // int arrSize = ARRAY_SIZE;
    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "outPosArrSize: " << outPosArrSize << endl;

    int *resultArray = getPosNums1(arr, ARRAY_SIZE, outPosArrSize);

    cout << "outPosArrSize: " << outPosArrSize << endl;

    // for (int i = 0; i < outPosArrSize; i++)
    // {
    //     cout << "resultArray[i]: " << resultArray[i] << endl;
    // }

    return 0;
}
