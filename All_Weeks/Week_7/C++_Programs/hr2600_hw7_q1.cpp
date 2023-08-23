#include <iostream>

using namespace std;

void printDaysOfWeek()
{

    cout << "MON"
         << "\t"
         << "TUE"
         << "\t"
         << "WED"
         << "\t"
         << "THR"
         << "\t"
         << "FRI"
         << "\t"
         << "SAT"
         << "\t"
         << "SUN"
         << "\t"
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

    if (isLeapYear(year) && numDays == 28)
    {
        numDays = 29;
    }

    return numDays;
}

void printYearCalender(int year, int startingDay)
{

    for (int i = 1; i <= 12; i++)
    {
        cout << endl;
        int numDays = printMonthHeader(i, year);
        int lastDayOfMonth = printMonthCalender(numDays, startingDay);
        if (lastDayOfMonth == 7)
        {
            startingDay = 1;
        }
        else
        {
            startingDay = lastDayOfMonth;
        }
    }
    cout << endl;
}

int main()
{

    int year;
    int startingDay;
    cout << "Please enter the year (i.e. 2016) and starting day (1-7) of the calendar you intend to print: " << endl;
    cin >> year;
    cin >> startingDay;
    
    printYearCalender(year, startingDay);

    return 0;
}
