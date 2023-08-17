#include <iostream>

using namespace std;

const string MON = "MON";
const string TUE = "TUE";
const string WED = "WED";
const string THR = "THR";
const string FRI = "FRI";
const string SAT = "SAT";
const string SUN = "SUN";

void printDaysOfWeek()
{

    cout << MON << "\t"
         << TUE << "\t"
         << WED << "\t"
         << THR << "\t"
         << FRI << "\t"
         << SAT << "\t"
         << SUN << "\t"
         << endl;
}

int printMonthCalender(int numOfDays, int startingDay)
{
    printDaysOfWeek();

    int lastDay = 0;
    int newLineCounter = 1;
    int lastDayOfMonth = 0;
    int previousDay = startingDay - 1;

    if (startingDay > 1)
    {
        cout << string(previousDay, '\t');
    }

    for (int i = 1; i <= numOfDays; i++)
    {
        cout << i << "\t";

        if ((previousDay + i) % 7 == 0)
        {
            cout << endl;
            newLineCounter++;
        }

        if (newLineCounter == 5)
        {
            lastDay++;
        }
    }

    // cout << endl;
    // cout << endl;

    // cout << "newLineCounter: " << newLineCounter << endl;

    // lastDayOfMonth = lastDay;

    // cout << "lastDayOfMonth: " << lastDayOfMonth << endl;

    return lastDay;
}

bool isLeapYear(int year)
{

    bool isCondition = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

    if (isCondition)
    {
        return true;
    }

    return false;
}

int printMonthHeader(int num, int year)
{
    cout << endl;

    int numDays = 0;
    switch (num)
    {
    case 1:
        cout << "January " << year << endl;
        numDays = 31;
        break;

    case 2:
        cout << "February " << year << endl;
        numDays = 28;
        break;

    case 3:
        cout << "March " << year << endl;
        numDays = 31;
        break;

    case 4:
        cout << "April " << year << endl;
        numDays = 30;
        break;

    case 5:
        cout << "May " << year << endl;
        numDays = 31;
        break;

    case 6:
        cout << "June " << year << endl;
        numDays = 30;
        break;

    case 7:
        cout << "July " << year << endl;
        numDays = 31;
        break;

    case 8:
        cout << "August " << year << endl;
        numDays = 31;
        break;

    case 9:
        cout << "September " << year << endl;
        numDays = 30;
        break;

    case 10:
        cout << "October " << year << endl;
        numDays = 31;
        break;

    case 11:
        cout << "November " << year << endl;
        numDays = 30;
        break;
    case 12:
        cout << "December " << year << endl;
        numDays = 31;
        break;
    default:
        numDays = 0;
        break;
    }

    // if(isLeapYear(year)){

    // }

    return numDays;
}

void printYearCalender(int year, int startingDay)
{

    for (int i = 1; i <= 12; i++)
    {
        int numDays = printMonthHeader(i, year);
        int lastDayOfMonth = printMonthCalender(numDays, startingDay);
        cout << "lastDayOfMonth: " << lastDayOfMonth << endl;
        startingDay = lastDayOfMonth;
    }
    cout << endl;
}

int main()
{
    // int lastDayOfMonth = printMonthCalender(31, 4);
    // cout << endl;
    // cout << "lastDayOfMonth: " << lastDayOfMonth << endl;

    // int year = 700;
    // cout << year << " is leap year: " << isLeapYear(year) << endl;

    int year = 2016;
    int startingDay = 5;
    printYearCalender(year, startingDay);

    return 0;
}
