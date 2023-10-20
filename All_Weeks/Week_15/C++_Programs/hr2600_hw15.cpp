#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

class Payments
{
private:
    string name;
    double paymentOwed;
    double paymentAmount;

    double getAveragePayment(list<Payments> paymentList)
    {
        double paymentTotal = 0.0;
        double averagePayment = 0.0;

        for (const Payments payment : paymentList)
        {
            paymentTotal += payment.getPaymentAmount();
        }

        averagePayment = paymentTotal / paymentList.size();

        return averagePayment;
    }

public:
    Payments(){};
    ~Payments() = default;

    string getName() const
    {
        return name;
    }

    double getPaymentOwed() const
    {
        return paymentOwed;
    }

    double getPaymentAmount() const
    {
        return paymentAmount;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void setPaymentOwed(double newPaymentOwed)
    {
        paymentOwed = newPaymentOwed;
    }

    void setPaymentAmount(double newPaymentAmount)
    {
        paymentAmount = newPaymentAmount;
    }

    void populatePaymentOwedField(list<Payments> &paymentList)
    {

        double averagePayment = getAveragePayment(paymentList);

        cout << "Average Payment: $" << averagePayment << endl;

        for (Payments &payment : paymentList)
        {
            payment.paymentOwed = averagePayment - payment.paymentAmount;
        }
    }
};

class FileProcessing
{

private:
    void openFile(ifstream &inputFile)
    {

        string fileName;

        cout << "What is the file name / path?" << endl;
        cin >> fileName;
        inputFile.open(fileName);

        while (!inputFile)
        {
            cout << "ERROR OPENING FILE" << endl;
            cout << "What is the file name / path?" << endl;
            cin >> fileName;
            inputFile.clear();
            inputFile.open(fileName);
        }
    }

public:
    FileProcessing(){};
    ~FileProcessing() = default;

    void getDataFile(ifstream &inputFile, list<Payments> &paymentList)
    {
        string name;
        double paymentAmount;

        openFile(inputFile);

        while (inputFile >> paymentAmount)
        {
            Payments payment;

            getline(inputFile, name);

            payment.setName(name);
            payment.setPaymentAmount(paymentAmount);
            payment.setPaymentOwed(0.0);

            paymentList.push_back(payment);
        }

        inputFile.close();
    }
};

int main()
{
    ifstream inputFile;
    Payments payments;
    list<Payments> paymentList;
    FileProcessing fileProcessing;

    fileProcessing.getDataFile(inputFile, paymentList);
    payments.populatePaymentOwedField(paymentList);

    // getPaymentOwed(paymentList);

    /*
    TODO:

    (1) Compare the payment.paymentOwed values and find a way to repay
        those that have negative values with those that have positive values
    */

    for (const Payments payment : paymentList)
    {

        if (payment.getPaymentOwed() < 0)
        {
            cout << payment.getName() << " is owed $" << payment.getPaymentOwed() << endl;
        }
        else if (payment.getPaymentOwed() > 0)
        {
            cout << payment.getName() << " owes $" << payment.getPaymentOwed() << endl;
        }
        else
        {
            cout << payment.getName() << ", doesn't have to do anything." << endl;
        }
    }

    return 0;
}
