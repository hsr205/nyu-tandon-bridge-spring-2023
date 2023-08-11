#include <iostream>

using namespace std;

int main()
{
    const int MINUTES_AN_HOUR = 60;
    const int MINUTES_IN_TWO_HOURS = 120;
    const int HOURS_IN_DAY = 24;
    const int HOURS_IN_TWO_DAYS = 48;

    int days;
    int hours;
    int minutes;
    int totalDays;
    int totalHours;
    int totalMinutes;

    cout << "Please enter the number of days John has worked: ";
    cin >> days;
    totalDays = days;

    cout << "Please enter the number of hours John has worked: ";
    cin >> hours;
    totalHours = hours;

    cout << "Please enter the number of minutes John has worked: ";
    cin >> minutes;
    totalMinutes = minutes;

    cout << endl;
    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> days;
    totalDays += days;

    cout << "Please enter the number of hours Bill has worked: ";
    cin >> hours;
    totalHours += hours;

    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> minutes;
    totalMinutes += minutes;

    if (totalHours == HOURS_IN_DAY || totalHours == HOURS_IN_TWO_DAYS || totalHours % HOURS_IN_DAY != 0)
    {
        int remainingHours = totalHours % HOURS_IN_DAY;
        int remainingDays = totalHours / HOURS_IN_DAY;
        totalHours = remainingHours;
        totalDays += remainingDays;
    }

    if (totalMinutes == MINUTES_AN_HOUR || totalMinutes == MINUTES_IN_TWO_HOURS || totalMinutes % MINUTES_AN_HOUR != 0)
    {
        int remainingMinutes = totalMinutes % MINUTES_AN_HOUR;
        int remainingHours = totalMinutes / MINUTES_AN_HOUR;
        totalMinutes = remainingMinutes;
        totalHours += remainingHours;
    }

    cout << endl;
    cout << endl;

    cout << "The total time both of them worked together is: " << totalDays << " days, " << totalHours << " hours and " << totalMinutes << " minutes." << endl;

    return 0;
}
