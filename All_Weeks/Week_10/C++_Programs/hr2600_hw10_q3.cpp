#include <iostream>
#include <vector>
#include <list>

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

list<int> insertInputValuesToList()
{
    int inputValue;
    list<int> resultList;
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
            resultList.push_back(inputValue);
        }
    }

    return resultList;
}

void printResult1(int searchNum, vector<int> searchNumLineAppearences)
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
void printResult2(int searchNum, list<int> searchNumLineAppearences)
{

    if (searchNumLineAppearences.size() > 0)
    {
        cout << searchNum << " shows in lines ";

        for (auto iterator = searchNumLineAppearences.begin(); iterator != searchNumLineAppearences.end(); iterator++)
        {
            if (iterator == searchNumLineAppearences.end())
            {
                cout << *iterator << ".";
            }
            else
            {
                cout << *iterator << ", ";
            }
        }
        cout << endl;
    }

    else
    {
        cout << searchNum << " was not found." << endl;
    }
}

void findNumLocation2()
{

    int cnt = 0;
    int searchNum;
    list<int> searchNumLineAppearences;
    list<int> inputValueList = insertInputValuesToList();

    cout << "Please enter you want to search." << endl;
    cin >> searchNum;

    for (const auto &element : inputValueList)
    {
        cnt++;
        if (searchNum == element)
        {
            searchNumLineAppearences.push_back(cnt);
        }
    }

    printResult2(searchNum, searchNumLineAppearences);
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

    printResult1(searchNum, searchNumLineAppearences);
}

void main1()
{
    findNumLocation1();
}

void main2()
{
    findNumLocation2();
}

int main()
{

    main1();
    main2();
    return 0;
}
