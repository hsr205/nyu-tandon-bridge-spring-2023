#include <iostream>

using namespace std;

bool isClubMember(char inputChar)
{

    if (inputChar == 'y')
    {
        return true;
    }

    return false;
}

int main()
{

    int itemPriceOne;
    int itemPriceTwo;
    double taxRate;
    char clubMemberFlag;

    cout << "Enter the price of first item: ";
    cin >> itemPriceOne;

    cout << "Enter the price of second item: ";
    cin >> itemPriceTwo;

    double intialPrice = itemPriceOne + itemPriceTwo;

    if (itemPriceOne < itemPriceTwo)
    {
        itemPriceOne *= .5;
    }
    else
    {
        itemPriceTwo *= .5;
    }

    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubMemberFlag;

    bool isMember = isClubMember(clubMemberFlag);

    cout << "Enter tax rate, e.g 5.5 for 5.5\% tax: ";
    cin >> taxRate;

    double basePrice = itemPriceOne + itemPriceTwo;

    cout << "Base price: " << intialPrice << endl;

    if (isMember)
    {
        double discountRate = .10;
        double discount = basePrice * discountRate;
        basePrice -= discount;
        cout << "Price after discounts: " << basePrice << endl;
    }

    taxRate = taxRate / 100.0;

    double totalPrice = (basePrice * taxRate) + basePrice;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);

    cout << "Total price: " << totalPrice << endl;

    return 0;
};