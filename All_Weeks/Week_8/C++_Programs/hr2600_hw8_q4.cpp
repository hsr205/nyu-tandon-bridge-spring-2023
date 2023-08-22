#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int ARRAY_SIZE = 10;
int pinNum = 12345;

void assignRandomValues()
{

    srand(static_cast<int>(time(nullptr)));

    int cnt = 0;
    int pinArray[ARRAY_SIZE];
    int randomArray[ARRAY_SIZE];
    int sequencialArray[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        randomArray[i] = rand() % 3 + 1;
    }

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        sequencialArray[i] = i;
    }

    while (pinNum > 0)
    {

        int digit = pinNum % 10;
        pinArray[cnt] = digit;
        pinNum /= 10;
        cnt++;
    }

//     for (int i = 0; i < ARRAY_SIZE; i++)
//     {
//         // cout << "randomArray[i]: " << randomArray[i] << endl;
//         // cout << "sequencialArray[i]: " << sequencialArray[i] << endl;

//     }
// }

void getUserInput()
{

    // int inputValue;

    // cout << "Please enter your PIN according to the following mapping: " << endl;

    // assignRandomValues();

    // cin >> inputValue;
}

int main()
{

    // getUserInput();
    assignRandomValues();
    return 0;
}
