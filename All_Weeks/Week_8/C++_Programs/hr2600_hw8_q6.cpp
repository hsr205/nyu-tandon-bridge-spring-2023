#include <iostream>
#include <string>

using namespace std;

void getUserInput()
{
    string inputStr = "My userid is john17 and my 4 digit pin is 1234 which is secret";
    cout << inputStr << endl;

    int indexStart = 0;
    int indexPosition = 0;
    string currentWord;
    string lastWord;
    string newSentence;

    for (int i = 0; i < inputStr.length(); i++)
    {
        if (inputStr[i] == ' ')
        {
            currentWord = inputStr.substr(indexStart, i - indexStart);

            indexPosition = currentWord.find_first_of("0123456789");
            if (indexPosition == 0)
            {
                currentWord = string(currentWord.length(), 'x');
            }
            newSentence += currentWord + " ";
            indexStart = i + 1;
        }
    }

    indexPosition = 0;

    lastWord = inputStr.substr(indexStart);

    indexPosition = lastWord.find_first_of("0123456789");

    if (indexPosition == 0)
    {
        lastWord = string(lastWord.length(), 'x');
    }

    cout << newSentence + lastWord << endl;
}

int main()
{

    getUserInput();
    return 0;
}
