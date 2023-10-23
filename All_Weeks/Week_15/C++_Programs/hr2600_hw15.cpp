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

    void getAveragePayment(list<Payments> paymentList, double &averagePayment)
    {
        double paymentTotal = 0.0;

        for (const Payments payment : paymentList)
        {
            paymentTotal += payment.getPaymentAmount();
        }

        averagePayment = paymentTotal / paymentList.size();
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

    void populatePaymentOwedField(list<Payments> &paymentList, double &averagePayment)
    {

        getAveragePayment(paymentList, averagePayment);

        for (Payments &payment : paymentList)
        {
            payment.paymentOwed = payment.paymentAmount - averagePayment;
        }
    }

    void populateListObjects(list<Payments> &paymentList, list<Payments> &paymentsOwedList, list<Payments> &paymentsToPayList)
    {
        for (const Payments payment : paymentList)
        {

            if (payment.getPaymentOwed() < 0)
            {
                paymentsToPayList.push_back(payment);
            }
            else if (payment.getPaymentOwed() > 0)
            {
                paymentsOwedList.push_back(payment);
            }
            else
            {
                cout << payment.getName() << ", you don't have to do anything." << endl;
            }
        }
    }

    void displayResults(list<Payments> &paymentsOwedList, list<Payments> &paymentsToPayList, double &averagePayment)
    {
        for (Payments &owes : paymentsToPayList)
        {

            while (owes.getPaymentOwed() < 0)
            {

                for (Payments &owed : paymentsOwedList)
                {

                    if (owed.getPaymentOwed() > 0 && owes.getPaymentOwed() != 0.0)
                    {
                        double transferAmount = min(-owes.getPaymentOwed(), owed.getPaymentOwed());

                        double paymentToPay = owes.getPaymentOwed() + transferAmount;
                        double paymentOwed = owed.getPaymentOwed() - transferAmount;

                        owes.setPaymentOwed(paymentToPay);
                        owed.setPaymentOwed(paymentOwed);

                        cout << owes.getName() << ", you give " << owed.getName() << " $" << transferAmount << endl;

                        if (owes.getPaymentOwed() == 0.0)
                        {
                            break;
                        }
                    }
                }

                break;
            }
        }

        cout << "In the end you should all have spent around $" << averagePayment << endl;
    }

    void displayPayments(list<Payments> listObject)
    {
        cout << string(20, '=') << endl;
        for (const Payments payment : listObject)
        {
            cout << payment.getName() << " -> $" << payment.getPaymentAmount() << " -> $" << payment.getPaymentOwed() << endl;
        }
        cout << string(20, '=') << endl;
    }
};

class FileProcessing
{

private:
    void openFile(ifstream &inputFile)
    {

        string fileName;

        cout << "Enter the file name: ";
        cin >> fileName;
        inputFile.open(fileName);

        while (!inputFile)
        {
            cout << "ERROR OPENING FILE" << endl;
            cout << "Enter the file name: ";
            cin >> fileName;
            inputFile.clear();
            inputFile.open(fileName);
        }
    }

public:
    FileProcessing(){};
    ~FileProcessing() = default;

    void getFileData(ifstream &inputFile, list<Payments> &paymentList)
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
    double averagePayment = 0.0;
    list<Payments> paymentList;
    list<Payments> paymentsOwedList;
    list<Payments> paymentsToPayList;
    FileProcessing fileProcessing;

    fileProcessing.getFileData(inputFile, paymentList);
    payments.populatePaymentOwedField(paymentList, averagePayment);
    payments.populateListObjects(paymentList, paymentsOwedList, paymentsToPayList);
    payments.displayResults(paymentsOwedList, paymentsToPayList, averagePayment);

    return 0;
}
