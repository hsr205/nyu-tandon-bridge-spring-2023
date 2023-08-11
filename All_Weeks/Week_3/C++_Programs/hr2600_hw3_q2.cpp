#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inputName;
    int graduationYear;
    int currentYear;

    cout << "Please enter your name: ";
    cin >> inputName;

    cout << "Please enter your graduation year: ";
    cin >> graduationYear;

    cout << "Please enter current year: ";
    cin >> currentYear;

    int numYears = graduationYear - currentYear;

    if (numYears <= 0)
    {
        cout << inputName << " has graduated" << endl;
    }
    else if (numYears == 1)
    {
        cout << inputName << ", you are a Senior" << endl;
    }
    else if (numYears == 2)
    {
        cout << inputName << ", you are a Junior" << endl;
    }
    else if (numYears == 3)
    {
        cout << inputName << ", you are a Sophomore" << endl;
    }
    else if (numYears == 4)
    {
        cout << inputName << ", you are a Freshman" << endl;
    }
    else if (numYears > 4)
    {
        cout << inputName << " is not in college" << endl;
    }

    return 0;
}