#include <iostream>

using namespace std;

int main()
{

    const double quarters = 0.25;
    const double dimes = 0.10;
    const double nickels = 0.05;
    const double pennies = 0.01;

    int quartersTotal;
    int dimesTotal;
    int nickelsTotal;
    int penniesTotal;

    double dollars;
    double cents;
    double total;
    double result;

    cout << "Please enter your amount in the format of dollars and cents separated by a space: " << endl;
    cin >> dollars;
    cin >> cents;

    total = dollars + (cents / 100.0);

    quartersTotal = total / quarters;
    total -= quartersTotal * quarters;

    dimesTotal = total / dimes;
    total -= dimesTotal * dimes;

    nickelsTotal = total / nickels;
    total -= nickelsTotal * nickels;

    penniesTotal = total / pennies;
    total -= penniesTotal * pennies;

    cout << quartersTotal << " quarters, " << dimesTotal << " dimes, " << nickelsTotal << " nickels and " << penniesTotal << " pennies." << endl;

    return 0;
}