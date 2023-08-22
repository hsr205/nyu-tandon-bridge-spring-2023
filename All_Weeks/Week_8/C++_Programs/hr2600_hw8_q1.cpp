#include <iostream>

using namespace std;

const int ARRAY_SIZE = 20;

int minInArray(int arr[], int arrSize)
{
    int smallestValue = arr[0];

    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] < smallestValue)
        {
            smallestValue = arr[i];
        }
    }

    return smallestValue;
}

void findIndicesOfMinArrayValue(int arr[], int minArrayValue)
{

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (minArrayValue == arr[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

void getResult()
{

    int inputValue;
    int arr[ARRAY_SIZE];
    cout << "Please enter " << ARRAY_SIZE << " integers separated by a space: " << endl;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cin >> inputValue;
        arr[i] = inputValue;
    }

    int smallestValue = minInArray(arr, ARRAY_SIZE);

    cout << "The minimum value is " << smallestValue << ", and it is located in the following indices: ";
    findIndicesOfMinArrayValue(arr, smallestValue);
}

int main()
{

    getResult();

    return 0;
}
