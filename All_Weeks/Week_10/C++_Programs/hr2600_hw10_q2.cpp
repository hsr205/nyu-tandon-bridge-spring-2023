#include <iostream>
#include <set>

using namespace std;

int *findMissing(int arr[], int n, int &resArrSize)
{

    int *result = new int[resArrSize];

    set<int> collectionSet(arr, arr + n);

    for (int i = 0; i <= collectionSet.size(); i++)
    {
        if (collectionSet.find(i) == collectionSet.end())
        {
            result[resArrSize] = i;
            resArrSize++;
        }
    }

    return result;
}

int main()
{
    int resArrSize = 0;
    int arr[] = {3, 1, 3, 0, 6, 4};

    cout << "resArrSize: " << resArrSize << endl;

    int *resultArray = findMissing(arr, 6, resArrSize);

    cout << "resArrSize: " << resArrSize << endl;

    for (int i = 0; i < resArrSize; i++)
    {
        cout << "resultArray[i]: " << resultArray[i] << endl;
    }

    delete[] resultArray;

    return 0;
}
