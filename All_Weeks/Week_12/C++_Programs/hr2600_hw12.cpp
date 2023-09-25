#include <iostream>

using namespace std;

class Money
{

private:
    double amount;

public:
    Money()
    {
        amount = 0.0;
    };
    Money(double amount)
    {
        this->amount = amount;
    };

    double getAmount() const
    {
        return amount;
    }
};

class Check
{

private:
    int checkNum;
    Money amount;
    bool isCashed;

public:
    Check()
    {
        checkNum = 0;
        amount = 0.0;
        isCashed = false;
    }
    Check(int checkNum, Money amount, bool isCashed)
    {
        this->checkNum = checkNum;
        this->amount = amount;
        this->isCashed = isCashed;
    }
    ~Check()
    {
    }

    int getCheckNumber() const
    {
        return checkNum;
    }

    Money getCheckAmount() const
    {
        return amount;
    }

    bool getIsCashed() const
    {
        return isCashed;
    }

    void setCheckNumber(int checkNum)
    {
        this->checkNum = checkNum;
    }

    void setCheckAmount(Money amount)
    {
        this->amount = amount;
    }

    void setIsCashed(bool isCashed)
    {
        this->isCashed = isCashed;
    }
};

bool getIsCashed(char cashedOrNotCashed)
{

    if (cashedOrNotCashed == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}

void getUserInput()
{

    int checkNum;
    double amount;
    char cashedOrNotCashed;
    bool isCashed;
    int exitProgramValue;
    int numChecks;
    int maxNumChecks;

    cout << "Please enter the number of check you wish to deposit: ";
    cin >> numChecks;

    Check *check = new Check[numChecks];

    for (int i = 0; i < numChecks; i++)
    {
        maxNumChecks++;

        cout << "Please enter the check number: ";
        cin >> checkNum;
        check[i].setCheckNumber(checkNum);

        cout << "Please enter the check amount: ";
        cin >> amount;
        check[i].setCheckAmount(amount);

        cout << "Please enter if the check was cashed or not (Y = cashed, N = not cashed): ";
        cin >> cashedOrNotCashed;

        isCashed = getIsCashed(cashedOrNotCashed);

        if (maxNumChecks == numChecks)
        {
            break;
        }

        check[i] = Check(checkNum, amount, isCashed);

        cout << "If you'd like to exit the program please enter the value -1 other wise enter 0: ";
        cin >> exitProgramValue;
        cout << endl;

        if (exitProgramValue == -1)
        {
            break;
        }
    }

    for (int i = 0; i < numChecks; i++)
    {
        cout << "Check Number: " << check[i].getCheckNumber() << endl;
    }

    delete[] check;

    // Check check = Check(checkNum, Money(amount), isCashed);

    // cout << "Check Number: " << check.getCheckNumber() << endl;
    // cout << "Check Amount: " << check.getCheckAmount().getAmount() << endl;
    // cout << "Is Check Cashed: " << check.getIsCashed() << endl;
}

int main()
{

    getUserInput();

    return 0;
}
