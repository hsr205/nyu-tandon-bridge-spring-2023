#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include <map>

using namespace std;

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

void printPinSequence(map<int, int> map)
{
    cout << "PIN: ";

    for (const auto &keyValue : map)
    {
        cout << keyValue.first << "  ";
    }
    cout << endl;
}

void printRandomNumSequence(map<int, int> map)
{
    cout << "NUM: ";

    for (const auto &keyValue : map)
    {
        cout << keyValue.second << "  ";
    }
    cout << endl;
}

vector<int> getIntVector(int inputPin)
{
    vector<int> result;

    while (inputPin > 0)
    {

        int digit = inputPin % 10;

        result.push_back(digit);

        inputPin /= 10;
    }

    return result;
}

bool isValidPin(int inputPin, int actualPin, map<int, int> map)
{
    int cnt = 0;
    vector<int> actualPinVector = getIntVector(actualPin);
    vector<int> inputPinVector = getIntVector(inputPin);

    reverse(actualPinVector.begin(), actualPinVector.end());
    reverse(inputPinVector.begin(), inputPinVector.end());

    for (const auto &keyValue : map)
    {
        for (int i = 0; i < actualPinVector.size(); i++)
        {
            if (keyValue.first == actualPinVector[i])
            {
                if (keyValue.second == inputPinVector[i])
                {
                    cnt++;
                    if (cnt == 5)
                    {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void displayInterfaceValues()
{
    map<int, int> map = getMap();

    printPinSequence(map);
    printRandomNumSequence(map);
}

int getUserInput()
{

    int inputPin;

    cout << "Please enter your PIN according to the following mapping: " << endl;

    displayInterfaceValues();

    cin >> inputPin;

    return inputPin;
}

void getResult()
{
    int actualPin = 12345;
    map<int, int> map = getMap();
    int inputPin = getUserInput();

    if (isValidPin(inputPin, actualPin, map))
    {
        cout << "Your PIN is correct" << endl;
    }
    else
    {
        cout << "Your PIN is not correct" << endl;
    }
}

int main()
{

    getResult();

    return 0;
}
