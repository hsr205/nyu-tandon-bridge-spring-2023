#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isAllDigits(string inputString)
{
    for (char character : inputString)
    {
        if (!isdigit(character))
        {
            return 0;
        }
    }
    return 1;
}

string replaceDigitStrings(string inputText)
{
    int indexStart = 0;
    int indexPosition = 0;
    string currentWord;
    string lastWord;
    string newSentence;

    for (int i = 0; i < inputText.length(); i++)
    {
        if (inputText[i] == ' ')
        {
            currentWord = inputText.substr(indexStart, i - indexStart);

            if (isAllDigits(currentWord))
            {
                currentWord = string(currentWord.length(), 'x');
            }

            newSentence += currentWord + " ";
            indexStart = i + 1;
        }
    }

    lastWord = inputText.substr(indexStart);

    if (isAllDigits(lastWord))
    {
        lastWord = string(lastWord.length(), 'x');
    }

    newSentence = newSentence + lastWord;

    return newSentence;
}

void getCheckInput()
{

    string inputText;

    cout << "Please enter a line of text: " << endl;
    getline(cin, inputText);

    string newSentence = replaceDigitStrings(inputText);

    cout << newSentence << endl;
}

int main()
{

    getCheckInput();

    return 0;
}
