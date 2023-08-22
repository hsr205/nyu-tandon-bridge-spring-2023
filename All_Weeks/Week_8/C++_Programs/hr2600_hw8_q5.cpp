#include <iostream>
#include <string>

using namespace std;

void getResult()
{

    string firstName;
    string middleName;
    string lastName;

    cout << "Please enter your first, middle and last names in that order: " << endl;

    cin >> firstName;
    cin >> middleName;
    cin >> lastName;

    cout << lastName << ", " << firstName << " " << middleName.substr(0, 1) + "." << endl;
}

int main()
{
    getResult();
    return 0;
}
