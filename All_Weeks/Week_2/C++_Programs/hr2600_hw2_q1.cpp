#include <iostream>

using namespace std;

int main()
{

    const double quarters = 0.25;
    const double dimes = 0.10;
    const double nickels = 0.05;
    const double pennies = 0.01;

    int quarterInput;
    int dimeInput;
    int nickelInput;
    int pennyInput;
    double total;

    cout << "Please enter number of coins: " << endl;
    cout << "# of quarters: ";
    cin >> quarterInput;
    total += quarterInput * quarters;

    cout << "# of dimes: ";
    cin >> dimeInput;
    total += dimeInput * dimes;

    cout << "# of nickels: ";
    cin >> nickelInput;
    total += nickelInput * nickels;

    cout << "# of pennies: ";
    cin >> pennyInput;
    total += pennyInput * pennies;

    int dollars = floor(total);
    int cents = (total - dollars) * 100;

    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;

    return 0;
}
