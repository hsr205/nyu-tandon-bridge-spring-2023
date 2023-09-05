#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getOddNumsVector(int arr[], int arrSize)
{

    vector<int> result;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 != 0)
        {
            result.push_back(arr[i]);
        }
    }

    return result;
}

vector<int> getEvenNumsVector(int arr[], int arrSize)
{

    vector<int> result;

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] % 2 == 0)
        {
            result.push_back(arr[i]);
        }
    }

    reverse(result.begin(), result.end());

    return result;
}

vector<int> combineVectors(int arr[], int arrSize)
{

    vector<int> oddNumsVector = getOddNumsVector(arr, arrSize);
    vector<int> evenNumsVector = getEvenNumsVector(arr, arrSize);

    oddNumsVector.insert(oddNumsVector.end(), evenNumsVector.begin(), evenNumsVector.end());

    return oddNumsVector;
}

int *oddsKeepEvensFlip(int arr[], int arrSize)
{
    int *resultArray = new int[arrSize];
    vector<int> resultVector = combineVectors(arr, arrSize);

    for (int i = 0; i < arrSize; i++)
    {
        resultArray[i] = resultVector[i];
    }

    return resultArray;
}

void printResult(int arr[], int *resultArray, const int ARRAY_SIZE)
{
    cout << "Start Array: \t";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Final Array: \t";
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << resultArray[i] << " ";
    }
    cout << endl;
}

void test1()
{
    cout << "Test Number 1:" << endl;
    cout << "-----------------------------------" << endl;
    const int ARRAY_SIZE = 6;
    int arr[ARRAY_SIZE] = {5, 2, 11, 7, 6, 4};

    int *resultArray = oddsKeepEvensFlip(arr, ARRAY_SIZE);

    printResult(arr, resultArray, ARRAY_SIZE);

    cout << "-----------------------------------" << endl;
    cout << endl;

    delete[] resultArray;
}

void test2()
{
    cout << "Test Number 2:" << endl;
    cout << "-----------------------------------" << endl;
    const int ARRAY_SIZE = 9;
    int arr[ARRAY_SIZE] = {1, 1, 1, 5, 2, 11, 7, 6, 4};

    int *resultArray = oddsKeepEvensFlip(arr, ARRAY_SIZE);

    printResult(arr, resultArray, ARRAY_SIZE);

    cout << "-----------------------------------" << endl;
    cout << endl;

    delete[] resultArray;
}

void test3()
{
    cout << "Test Number 3:" << endl;
    cout << "-----------------------------------" << endl;
    const int ARRAY_SIZE = 6;
    int arr[ARRAY_SIZE] = {11, 7, 6, 4, 2, 5};

    int *resultArray = oddsKeepEvensFlip(arr, ARRAY_SIZE);

    printResult(arr, resultArray, ARRAY_SIZE);

    cout << "-----------------------------------" << endl;
    cout << endl;

    delete[] resultArray;
}

void test4()
{
    cout << "Test Number 4:" << endl;
    cout << "-----------------------------------" << endl;
    const int ARRAY_SIZE = 6;
    int arr[ARRAY_SIZE] = {4, 2, 5, 1, 5, 7};

    int *resultArray = oddsKeepEvensFlip(arr, ARRAY_SIZE);

    printResult(arr, resultArray, ARRAY_SIZE);

    cout << "-----------------------------------" << endl;
    cout << endl;

    delete[] resultArray;
}

int main()
{

    test1();
    test2();
    test3();
    test4();

    return 0;
}
