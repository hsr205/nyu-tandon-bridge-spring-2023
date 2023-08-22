#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str)
{
    string reversedString;

    for (int i = (str.length() - 1); i >= 0; i--)
    {
        reversedString += str[i];
    }

    if (str == reversedString)
    {
        cout << str << " is a palidrome" << endl;
        return 1;
    }

    cout << str << " is NOT a palidrome" << endl;
    return 0;
}

void getResult()
{
    string userInputStr;

    cout << "Please enter a word: ";
    cin >> userInputStr;

    isPalindrome(userInputStr);
}

int main()
{
    getResult();
    return 0;
}
