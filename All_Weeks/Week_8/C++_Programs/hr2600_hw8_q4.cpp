#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

int pinNum = 12345;

int *intToArray(int inputValue)
{

    int cnt = 0;

    vector<int> collection;
    while (inputValue > 0)
    {
        int digit = inputValue % 10;

        inputValue /= 10;
        collection.push_back(digit);
    }

    int *arr = new int[collection.size()];

    for (int i = (collection.size() - 1); i >= 0; i--)
    {
        arr[cnt] = collection[i];
        cnt++;
    }

    return arr;
}
map<int, int> getMap()
{
    srand(static_cast<int>(time(nullptr)));

    map<int, int> map;

    for (int i = 0; i < 10; i++)
    {
        map[i] = rand() % 3 + 1;
    }

    return map;
}

void getResultVector(int digit, vector<int> &collection)
{
    map<int, int> map = getMap();

    for (const auto &keyValue : map)
    {
        if (digit == keyValue.first)
        {
            collection.push_back(keyValue.second);
            cout << digit << " -> " << keyValue.second << endl;
        }
    }
}

vector<int> getCodedPin(int inputValue)
{

    vector<int> collection;

    int *codedPin = intToArray(inputValue);

    for (int i = 0; i < 5; i++)
    {
        int digit = codedPin[i];
        getResultVector(digit, collection);
    }

    return collection;
}

void printInterfaceValues()
{
    map<int, int> map = getMap();

    cout << "PIN: ";
    for (const auto &keyValue : map)
    {
        cout << keyValue.first << string(2, ' ');
    }
    cout << endl;

    cout << "NUM: ";
    for (const auto &keyValue : map)
    {
        cout << keyValue.second << string(2, ' ');
    }
    cout << endl;
}

void getUserInput()
{

    int inputValue;

    cout << "Please enter your PIN according to the following mapping: " << endl;
    printInterfaceValues();

    cin >> inputValue;

    vector<int> codedPinVector = getCodedPin(pinNum);
    int *inputValueArray = intToArray(inputValue);

    for (int i = 0; i < 5; i++)
    {
        if (codedPinVector[i] != inputValueArray[i])
        {
            cout << "Your PIN is incorrect" << endl;
        }
        else
        {
            cout << "Your PIN is correct" << endl;
        }
    }
}

int main()
{
    // vector<int> codedPin = getCodedPin(pinNum);

    // cout << "Coded Pin: ";
    // for (int element : codedPin)
    // {
    //     cout << element;
    // }
    // cout << endl;
    getUserInput();

    return 0;
}
