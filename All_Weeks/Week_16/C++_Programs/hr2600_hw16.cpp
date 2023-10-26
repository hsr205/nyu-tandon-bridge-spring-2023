#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

struct FileData
{
    string data;
};

void getInputFile(ifstream &inputFile)
{

    string inputFilePath = "data.txt";
    inputFile.open(inputFilePath);

    while (!inputFile)
    {

        cout << "ERROR OPENING FILE" << endl;
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

bool getResult(ifstream &inputFile)
{

    bool result = false;
    stack<char> tempStackObj;
    stack<char> stackObj = getInputFileData(inputFile);

    while (!stackObj.empty())
    {

        // char firstChar = stackObj.top();
        // tempStackObj.push(firstChar);
        // cout << "Top: " << tempStackObj.top() << endl;
        cout << "Top: " << stackObj.top() << endl;
        stackObj.pop();

        // while (!stackObj.empty())
        // {
        //     char secondChar = stackObj.top();
        //     cout << "SecondChar: " << secondChar << endl;
        //     stackObj.pop();
        // }
    }

    return result;
}

int main()
{
    ifstream inputFile;
    bool result = getResult(inputFile);

    if (result)
    {
        cout << "Result: True" << endl;
    }
    else
    {
        cout << "Result: False" << endl;
    }

    return 0;
}
