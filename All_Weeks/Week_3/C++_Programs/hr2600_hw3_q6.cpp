#include <iostream>
#include <string>

using namespace std;

string getDayOfWeek()
{
    string dayOfWeek;
    cout << "Please enter the day of the week (i.e. Mo = Monday, Tu = Tuesday, etc): ";
    cin >> dayOfWeek;
    return dayOfWeek;
}

double getLengthOfCallInMin()
{

    double lengthOfCallInMinutes;
    cout << "Please enter the length of the call in minutes (i.e. 45, 90, etc): ";
    cin >> lengthOfCallInMinutes;

    return lengthOfCallInMinutes;
}

void printTotal(double total)
{

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "The total cost of the call is: "
         << "$" << total << endl;
}

int main()
{

    const double REGULAR_RATE = 0.40;
    const double AFTER_HOURS_RATE = 0.25;
    const double WEEKEND_RATE = 0.15;
    string dayOfWeek = getDayOfWeek();

    int hours;
    int minutes;
    char colon;
    double total;

    cout << "Please enter the time of the call (i.e. 8:30, 14:30): ";
    cin >> hours;
    cin >> colon;
    cin >> minutes;

    double lengthOfCallInMinutes = getLengthOfCallInMin();

    bool isRegularHour = hours >= 8 && hours <= 18;
    bool isValidMinute = minutes >= 0;
    bool isRegularHours = isRegularHour && isValidMinute;

    bool isAfterHour = hours <= 8 || hours >= 18;
    bool isAfterHours = isAfterHour && isValidMinute;

    bool isWeekend = dayOfWeek == "Sa" || dayOfWeek == "Su";

    if (isWeekend)
    {
        total = lengthOfCallInMinutes * WEEKEND_RATE;
        printTotal(total);
        return 0;
    }

    if (isRegularHours)
    {
        total = lengthOfCallInMinutes * REGULAR_RATE;
        printTotal(total);
        return 0;
    }

    if (isAfterHours)
    {
        total = lengthOfCallInMinutes * AFTER_HOURS_RATE;
        printTotal(total);
        return 0;
    }

    return 0;
}
