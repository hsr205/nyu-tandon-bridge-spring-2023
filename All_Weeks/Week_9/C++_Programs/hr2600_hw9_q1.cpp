#include <iostream>
#include <string>
#include <cctype>
#include <map>

using namespace std;

string getUserInput()
{
    string userInput;

    cout << "Please enter a line of text: " << endl;
    getline(cin, userInput);

    return userInput;
}

vector<string> getStringVector(string inputText)
{

    // string inputText = "I say Hi.";
    int indexStart = 0;
    int indexPosition = 0;
    string currentWord;
    string lastWord;

    vector<string> result;

    for (int i = 0; i < inputText.length(); i++)
    {
        if (inputText[i] == ' ')
        {
            currentWord = inputText.substr(indexStart, i - indexStart);
            result.push_back(currentWord);
            indexStart = i + 1;
        }
    }

    lastWord = inputText.substr(indexStart);

    result.push_back(lastWord);

    return result;
}

void printResult(vector<string> strCollection, map<char, int> map)
{
    cout << strCollection.size() << "\t"
         << "words" << endl;

    for (const auto &element : map)
    {
        cout << element.first << "\t" << element.second << endl;
    }
}

map<char, int> getMapResult(vector<string> strCollection)
{
    vector<char> charCollection;
    map<char, int> resultMap;

    for (string element : strCollection)
    {
        for (char character : element)
        {
            charCollection.push_back(static_cast<char>(tolower(character)));
        }
    }

    for (char element : charCollection)
    {
        if (element == ',' || element == '.')
        {
            continue;
        }
        if (resultMap.find(element) != resultMap.end())
        {
            resultMap[element]++;
        }
        else
        {
            resultMap[element] = 1;
        }
    }

    return resultMap;
}

int main()
{
    string userInput = getUserInput();
    vector<string> stringVector = getStringVector(userInput);
    map<char, int> mapResult = getMapResult(stringVector);
    
    printResult(stringVector, mapResult);
    return 0;
}
