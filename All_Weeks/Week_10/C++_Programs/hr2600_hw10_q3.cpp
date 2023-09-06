#include <iostream>
#include <vector>

using namespace std;

vector<int> insertInputValuesToVector()
{

    int inputValue;
    vector<int> resultVector;
    cout << "Please enter a sequence of positive integers, each in a separte line." << endl;
    cout << "End your input by typing -1." << endl;

    while (true)
    {

        cin >> inputValue;

        if (inputValue == -1)
        {
            break;
        }

        else
        {
            resultVector.push_back(inputValue);
        }
    }

    return resultVector;
}

void printResult(int searchNum, vector<int> searchNumLineAppearences)
{

    if (searchNumLineAppearences.size() > 0)
    {
        cout << searchNum << " shows in lines ";
        for (int i = 0; i < searchNumLineAppearences.size(); i++)
        {
            if (i == searchNumLineAppearences.size() - 1)
            {
                cout << searchNumLineAppearences[i] << ".";
            }
            else
            {
                cout << searchNumLineAppearences[i] << ", ";
            }
        }
        cout << endl;
    }

    else
    {
        cout << searchNum << " was not found." << endl;
    }
}

void findNumLocation1()
{
    int cnt = 0;
    int searchNum;
    vector<int> searchNumLineAppearences;
    vector<int> inputValuesVector = insertInputValuesToVector();

    cout << "Please enter you want to search." << endl;
    cin >> searchNum;

    for (int i = 0; i < inputValuesVector.size(); i++)
    {
        cnt++;
        if (searchNum == inputValuesVector[i])
        {
            searchNumLineAppearences.push_back(cnt);
        }
    }

    printResult(searchNum, searchNumLineAppearences);
}

int main()
{

    findNumLocation1();
    return 0;
}
