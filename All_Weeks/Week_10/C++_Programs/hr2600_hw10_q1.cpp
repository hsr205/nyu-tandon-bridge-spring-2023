#include <iostream>
#include <string>

using namespace std;

string *createWordsArray(string sentence, int &outWordsArrSize)
{
    int indexStart = 0;
    string lastWord;
    string currentWord;
    string *stringArr = new string[outWordsArrSize];

    for (int i = 0; i < sentence.length(); i++)
    {

        if (sentence[i] == ' ')
        {

            currentWord = sentence.substr(indexStart, i - indexStart);
            stringArr[outWordsArrSize] = currentWord;
            indexStart = i + 1;
            outWordsArrSize++;
        }
    }

    lastWord = sentence.substr(indexStart);

    stringArr[outWordsArrSize] = lastWord;

    outWordsArrSize++;

    return stringArr;
}

int main()
{

    int outWordsArrSize = 0;
    string sentence = "You can do it";

    cout << "outWordsArrSize: " << outWordsArrSize << endl;

    string *result = createWordsArray(sentence, outWordsArrSize);

    cout << "outWordsArrSize: " << outWordsArrSize << endl;

    for (int i = 0; i < outWordsArrSize; i++)
    {
        cout << "result[i]: " << result[i] << endl;
    }

    return 0;
}
