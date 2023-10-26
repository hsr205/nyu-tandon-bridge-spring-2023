#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

void getInputFile(ifstream &inputFile)
{

    string inputFilePath;
    cout << "Please enter file name: ";
    cin >> inputFilePath;
    inputFile.open(inputFilePath);

    while (!inputFile)
    {

        cout << "ERROR OPENING FILE" << endl;
        cout << "Please enter file name: ";
        cin >> inputFilePath;
        inputFile.open(inputFilePath);

        return;
    }
}

stack<char> getInputFileData(ifstream &inputFile)
{

    bool result = false;
    stack<char> stackObj;
    string charactersStr;

    getInputFile(inputFile);

    while (inputFile >> charactersStr)
    {
        for (const char element : charactersStr)
        {

            stackObj.push(element);
        }
    }

    inputFile.close();

    return stackObj;
}

void checkStackObjForSymbol(stack<char> &stackObj, char charToFind)
{

    if (!stackObj.empty() && stackObj.top() == charToFind)
    {
        stackObj.pop();
    }
}

bool getResult(ifstream &inputFile)
{

    bool result = false;
    stack<char> tempStackObj;
    stack<char> stackObj = getInputFileData(inputFile);

    while (!stackObj.empty())
    {

        char topChar = stackObj.top();

        // cout << "Top Char: " << topChar << endl;

        switch (topChar)
        {

        case ']':
        case '}':
        case ')':
            tempStackObj.push(topChar);
            break;
        case '[':
            checkStackObjForSymbol(tempStackObj, ']');
            break;
        case '{':
            checkStackObjForSymbol(tempStackObj, '}');
            break;
        case '(':
            checkStackObjForSymbol(tempStackObj, ')');
            break;

        default:
            break;
        }

        stackObj.pop();
    }

    if (tempStackObj.empty())
    {
        result = true;
    }

    return result;
}

int main()
{
    ifstream inputFile;
    bool result = getResult(inputFile);

    if (result)
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
