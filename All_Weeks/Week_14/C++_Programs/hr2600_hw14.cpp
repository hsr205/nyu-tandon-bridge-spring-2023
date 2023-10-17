#include <iostream>
#include <vector>
#include <string>

using namespace std;

void mergeVectors(vector<int> &inputVector, int leftPos, int leftEnd, int rightEnd, vector<int> &tempVector)
{
    int rightPos = leftEnd + 1;
    int tempPos = leftPos;
    int originalStart = leftPos;

    while (leftPos <= leftEnd && rightPos <= rightEnd)
    {
        if (inputVector[leftPos] < inputVector[rightPos])
        {
            tempVector[tempPos++] = inputVector[leftPos++];
        }
        else
        {
            tempVector[tempPos++] = inputVector[rightPos++];
        }
    }

    while (leftPos <= leftEnd)
    {
        tempVector[tempPos++] = inputVector[leftPos++];
    }
    while (rightPos <= rightEnd)
    {
        tempVector[tempPos++] = inputVector[rightPos++];
    }

    for (int i = originalStart; i <= rightEnd; i++)
    {
        inputVector[i] = tempVector[i];
    }
}

void mergeSort(vector<int> &inputVector, int start, int end, vector<int> &tempVector)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(inputVector, start, mid, tempVector);
        mergeSort(inputVector, mid + 1, end, tempVector);
        mergeVectors(inputVector, start, mid, end, tempVector);
    }
}

void getMinMaxValues(vector<int> &inputVector)
{

    if (inputVector.size() > 2)
    {
        inputVector.erase(inputVector.begin() + 1, inputVector.end() - 1);
    }
}

void getMinMax(vector<int> &inputVector)
{

    vector<int> tempVector;
    tempVector.resize(inputVector.size());
    mergeSort(inputVector, 0, inputVector.size() - 1, tempVector);
}

void testOne()
{
    vector<int> inputVector = {7, 2, 9, 6, 1, 5, 10, 3, 8, 4};

    cout << "Test One: " << endl;

    cout << string(20, '=') << endl;

    cout << "Original Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;

    getMinMax(inputVector);
    getMinMaxValues(inputVector);

    cout << "Result Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;
    cout << endl;
}

void testTwo()
{
    vector<int> inputVector = {2, 6, 19, 7, 3, 9, 5};

    cout << "Test Two: " << endl;

    cout << string(20, '=') << endl;

    cout << "Original Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;

    getMinMax(inputVector);
    getMinMaxValues(inputVector);

    cout << "Result Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;
    cout << endl;
}

void testThree()
{
    vector<int> inputVector = {15, 7, 4, 9, 6, -4, 10};

    cout << "Test Three: " << endl;

    cout << string(20, '=') << endl;

    cout << "Original Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;

    getMinMax(inputVector);
    getMinMaxValues(inputVector);

    cout << "Result Vector: " << endl;

    for (const int element : inputVector)
    {
        cout << element << " ";
    }

    cout << endl;
    cout << string(20, '=') << endl;
    cout << endl;
}

int main()
{
    testOne();
    testTwo();
    testThree();

    return 0;
}
