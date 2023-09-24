#include <iostream>

using namespace std;

class Money
{

private:
    int cents;
    long dollars;

public:
    Money();

    Money(long dollars)
    {
        this->dollars = dollars;
    };

    Money(long dollars, int cents)
    {
        this->dollars = dollars;
        this->cents = cents;
    };

    double getValue() const
    {

        int cents = this->cents;
        long dollars = this->dollars;

        int cnt = 0;
        double total = 0.0;
        double remainingCents = 0;

        while (cents > 99)
        {

            if (cents % 100 == 0)
            {
                dollars += cents / 100;
            }
            else
            {
                dollars += cents / 100;
                remainingCents += cents % 100;
            }
            cnt++;
            cents /= 100;
        }

        if (cnt == 0)
        {
            remainingCents = cents;
        }

        total = dollars + (remainingCents / 100);

        return total;
    };

    long getDollars() const
    {
        return dollars;
    }

    int getCents() const
    {
        return cents;
    }
};

class CheckBook
{

private:
    int checkNumber;
    int checkAmount;
    bool isCashed;
    // Money moneyObj;

public:
    // CheckBook(int checkNumber, int checkAmount, bool isCashed, const Money &moneyObj)
    // {
    //     this->checkNumber = checkNumber;
    //     this->checkAmount = checkAmount;
    //     this->isCashed = isCashed;
    //     this->moneyObj = moneyObj;
    // }
    CheckBook(int checkNumber, int checkAmount, bool isCashed)
    {
        this->checkNumber = checkNumber;
        this->checkAmount = checkAmount;
        this->isCashed = isCashed;
    }

    int getCheckNumber() const
    {
        return checkNumber;
    }

    int getCheckAmount() const
    {
        return checkAmount;
    }

    bool getIsCashed() const
    {
        return isCashed;
    }
};

int main()
{

    Money money1 = Money(12, 1211);
    // CheckBook checkBook = CheckBook(12345, 100, 1, money1);
    CheckBook checkBook = CheckBook(12345, 100, 1);

    cout << "Check Number: " << checkBook.getCheckNumber() << endl;
    cout << "Check Amount: " << checkBook.getCheckAmount() << endl;
    cout << "Is check cashed: " << checkBook.getIsCashed() << endl;

    // Money money1 = Money(12, 1211);

    // // cout << "Dollars: " << money1.getDollars() << endl;
    // // cout << "Cents: " << money1.getCents() << endl;

    // // cout << endl;

    // cout << "Total Value: " << money1.getValue() << endl;

    return 0;
}
