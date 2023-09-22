#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isBinary(char character)
{
    if (character != '0' && character != '1')
    {
        return false;
    }

    return true;
}

void getUserInput()
{

    string inputString;

    vector<string> binaryStringMap;
    vector<string> remainingStringVector;

    int nonBinaryCnt = 0;

    cout << "Please enter a non-empty sequence of Strings." << endl;
    cout << "Each string should be in a separate line and consists of only decimal digit characters." << endl;
    cout << "To indicate the end of the input, enter an empty string in one line." << endl;

    while (true)
    {

        getline(cin, inputString);
        if (inputString.empty())
        {
            break;
        }

        for (char character : inputString)
        {

            if (character != '0' && character != '1')
            {

                nonBinaryCnt++;
            }
        }

        // cout << "nonBinaryCnt: " << nonBinaryCnt << endl;

        if (nonBinaryCnt == 0)
        {
            binaryStringMap.push_back(inputString);
        }
        else
        {
            remainingStringVector.push_back(inputString);
        }

        nonBinaryCnt = 0;
    }

    // cout << "binaryStringMap: " << endl;

    for (string element : binaryStringMap)
    {

        cout << element << endl;
    }

    cout << "Number of Strings in the input sequence that get deleted for containing " << endl;
    cout << "at least one character which is not 0 or 1: " << remainingStringVector.size() << endl;
}

int main()
{

    getUserInput();
    return 0;
}
