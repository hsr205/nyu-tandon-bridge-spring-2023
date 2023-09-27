#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <list>
#include <map>

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

string getDollarFormat(double doubleVal)
{
    ostringstream ss;

    if (doubleVal < 0)
    {
        ss << fixed << setprecision(2) << "-$" << abs(doubleVal);
    }
    else
    {
        ss << fixed << setprecision(2) << "$" << doubleVal;
    }

    string result = ss.str();

    return result;
}

map<int, list<pair<double, bool>>> getCheckData()
{

    int checkNum;
    double amount;
    bool isCashed;
    int numChecks;
    double sumCashedChecks;
    double sumUnCashedChecks;
    map<int, list<pair<double, bool>>> resultMap;

    cout << "Please enter the check number, amount of check [exclude the dollar sign] and whether or not the check was cashed (0 = No, 1 = Yes): " << endl;
    cout << "Example input: " << endl;
    cout << "9 for check number, 40.89 for check amount and 1 for a cashed check (9 40.89 1) " << endl;

    cout << endl;

    cout << "Please enter the number of check(s): ";
    cin >> numChecks;

    Check *check = new Check[numChecks];

    for (int i = 0; i < numChecks; i++)
    {
        cin >> checkNum;
        check[i].setCheckNumber(checkNum);

        cin >> amount;
        check[i].setCheckAmount(amount);

        cin >> isCashed;
        check[i].setIsCashed(isCashed);

        if (isCashed == 0)
        {
            sumCashedChecks += amount;
        }
        else
        {
            sumUnCashedChecks += amount;
        }

        check[i] = Check(checkNum, amount, isCashed);

        resultMap[checkNum].push_back(make_pair(amount, isCashed));
    }

    cout << endl;

    cout << "The sum of cashed checks is: " << endl;
    cout << getDollarFormat(sumCashedChecks) << endl;

    cout << "The sum of un-cashed checks is: " << endl;
    cout << getDollarFormat(sumUnCashedChecks) << endl;

    delete[] check;

    return resultMap;
}

double getDepositInput()
{
    int numDeposits;
    double depositAmount;
    double sumOfDeposits;

    cout << endl;
    cout << "Please enter deposits in the following format: ##.## " << endl;
    cout << "Please enter the number of deposit(s): ";
    cin >> numDeposits;

    Money *deposit = new Money[numDeposits];

    for (int i = 0; i < numDeposits; i++)
    {
        cin >> depositAmount;

        sumOfDeposits += depositAmount;
    }

    cout << "The sum of the deposit(s) is: " << endl;
    cout << getDollarFormat(sumOfDeposits) << endl;

    delete[] deposit;

    return sumOfDeposits;
}

int getSumChecks(map<int, double> checksMap)
{
    double sumChecks;

    for (auto &keyValue : checksMap)
    {
        sumChecks += keyValue.second;
    }

    return sumChecks;
}

void getAccountBalanceData(double sumOfDeposits, map<int, double> cashedChecksMap)
{

    double priorBalance;
    double currentBalance;
    double sumCashedChecks;

    for (auto &keyValue : cashedChecksMap)
    {
        sumCashedChecks += keyValue.second;
    }

    cout << endl;
    cout << "Please enter the prior balance amount in the following format: ##.##" << endl;
    cin >> priorBalance;

    cout << "Please enter the new balance according to the account holder in the following format: ##.##" << endl;
    cin >> currentBalance;

    cout << endl;

    double bankBalance = priorBalance + sumOfDeposits - sumCashedChecks;

    string bankBalanceStr = getDollarFormat(bankBalance);
    string currentBalanceStr = getDollarFormat(currentBalance);
    string resultDiff = getDollarFormat(bankBalance - currentBalance);

    cout << "The balance according to the bank which includes only cleared checks is: " << bankBalanceStr << endl;
    cout << "The difference between the account holders balance of " << currentBalanceStr << " and the bank balance of " << bankBalanceStr << " is: " << resultDiff << endl;
}

void displayCheckData(map<int, double> map)
{
    for (auto &keyValue : map)
    {
        cout << "Check number: " << keyValue.first << " with the amount: " << getDollarFormat(keyValue.second) << endl;
    }
}

map<int, double> getCashedChecksMap(map<int, list<pair<double, bool>>> mapObj)
{
    map<int, double> cashedChecksMap;

    for (auto &keyValue : mapObj)
    {
        list<pair<double, bool>> listVals = keyValue.second;

        for (auto &pairVals : listVals)
        {
            if (pairVals.second)
            {
                cashedChecksMap[keyValue.first] = pairVals.first;
            }
        }
    }

    return cashedChecksMap;
}

void getCheckResult(map<int, list<pair<double, bool>>> mapObj)
{
    cout << endl;

    map<int, double> cashedChecksMap;
    map<int, double> unCashedChecksMap;

    for (auto &keyValue : mapObj)
    {
        list<pair<double, bool>> listVals = keyValue.second;

        for (auto &pairVals : listVals)
        {
            if (pairVals.second)
            {
                cashedChecksMap[keyValue.first] = pairVals.first;
            }
            else
            {
                unCashedChecksMap[keyValue.first] = pairVals.first;
            }
        }
    }

    cout << "The cashed checks are: " << endl;

    displayCheckData(cashedChecksMap);

    cout << endl;

    cout << "The un-cashed checks are: " << endl;

    displayCheckData(unCashedChecksMap);
}

int main()
{

    map<int, list<pair<double, bool>>> result = getCheckData();
    double sumOfDeposits = getDepositInput();
    map<int, double> cashedChecksMap = getCashedChecksMap(result);
    getAccountBalanceData(sumOfDeposits, cashedChecksMap);
    getCheckResult(result);

    return 0;
}
