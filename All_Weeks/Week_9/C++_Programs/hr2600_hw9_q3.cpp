#include <iostream>

using namespace std;

const int ARRAY_SIZE = 6;

int *getPosNums1(int *arr, int arrSize, int &outPosArrSize)
{

    int *resultArray = new int[ARRAY_SIZE];

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            resultArray[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

    return resultArray;
}

void testGetPosNums1Method()
{
    int outPosArrSize = 0;

    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "outPosArrSize: " << outPosArrSize << endl;

    int *resultArray = getPosNums1(arr, ARRAY_SIZE, outPosArrSize);

    cout << "outPosArrSize: " << outPosArrSize << endl;

    for (int i = 0; i < outPosArrSize; i++)
    {
        cout << "resultArray[i]: " << resultArray[i] << endl;
    }

    delete[] resultArray;
}

int *getPosNums2(int *arr, int arrSize, int *outPosArrSizePtr)
{

    int *resultArray = new int[*outPosArrSizePtr];

    int tempValue = 0;
    int *ptr = &tempValue;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            resultArray[tempValue] = arr[i];
            tempValue++;
        }
    }

    return resultArray;
}

void testGetPosNums2Method()
{
    int tempValue = 0;
    int *outPosArrSizePtr = &tempValue;

    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "*outPosArrSizePtr: " << *outPosArrSizePtr << endl;

    int *resultArray = getPosNums2(arr, ARRAY_SIZE, outPosArrSizePtr);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (arr[i] > 0)
        {
            tempValue++;
        }
    }

    cout << "*outPosArrSizePtr: " << *outPosArrSizePtr << endl;

    for (int i = 0; i < *outPosArrSizePtr; i++)
    {
        cout << "resultArray[i]: " << resultArray[i] << endl;
    }

    delete[] resultArray;
}

int *getPosNums3(int *arr, int arrSize, int *&outPosArr, int &outPosArrSize)
{

    int *resultArray = new int[ARRAY_SIZE];

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            resultArray[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

    outPosArr = resultArray;

    return outPosArr;
}

void testGetPosNums3Method()
{
    int tempValue = 0;
    int *outPosArr = &tempValue;
    int outPosArrSize = 0;

    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "outPosArr: " << *outPosArr << endl;

    int *resultArray = getPosNums3(arr, ARRAY_SIZE, outPosArr, outPosArrSize);

    cout << "outPosArrSize: " << outPosArrSize << endl;

    for (int i = 0; i < outPosArrSize; i++)
    {
        cout << "resultArray[i]: " << resultArray[i] << endl;
    }

    delete[] resultArray;
}

int *getPosNums4(int *arr, int arrSize, int **outPosArrPointer, int &outPosArrSize)
{

    int *resultArray = new int[ARRAY_SIZE];

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] > 0)
        {
            resultArray[outPosArrSize] = arr[i];
            outPosArrSize++;
        }
    }

    *outPosArrPointer = resultArray;
    resultArray = *outPosArrPointer;

    return resultArray;
}

void testGetPosNums4Method()
{
    int tempValue = 0;
    int *outPosArrPtr = nullptr;
    int outPosArrSize = 0;

    int arr[ARRAY_SIZE] = {3, -1, -3, 0, 6, 4};

    cout << "outPosArrSize: " << outPosArrSize << endl;

    int *resultArray = getPosNums4(arr, ARRAY_SIZE, &outPosArrPtr, outPosArrSize);

    cout << "outPosArrSize: " << outPosArrSize << endl;

    for (int i = 0; i < outPosArrSize; i++)
    {
        cout << "resultArray[i]: " << resultArray[i] << endl;
    }

    delete[] resultArray;
}

void printResults()
{
    cout << "Testing getPosNums1() method: " << endl;
    cout << "---------------------------------" << endl;
    testGetPosNums1Method();
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Testing getPosNums2() method: " << endl;
    cout << "---------------------------------" << endl;
    testGetPosNums2Method();
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Testing getPosNums3() method: " << endl;
    cout << "---------------------------------" << endl;
    testGetPosNums3Method();
    cout << "---------------------------------" << endl;
    cout << endl;

    cout << "Testing getPosNums4() method: " << endl;
    cout << "---------------------------------" << endl;
    testGetPosNums4Method();
    cout << "---------------------------------" << endl;
    cout << endl;
}

int main()
{
    printResults();
    return 0;
}
