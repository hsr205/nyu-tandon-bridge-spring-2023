#include <iostream>
#include <string>
#include <fstream>
#include <list>

using namespace std;

struct Payments
{
    double paymentAmount;
    string name;
};

class FileProcessing
{

public:
    FileProcessing(){};
    ~FileProcessing() = default;

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

    void getDataFile(ifstream &inputFile, list<Payments> &paymentList)
    {
        string name;
        double paymentAmount;

        openFile(inputFile);

        while (inputFile >> paymentAmount)
        {
            Payments payment;

            getline(inputFile, name);

            payment.name = name;
            payment.paymentAmount = paymentAmount;

            paymentList.push_back(payment);
        }

        inputFile.close();
    }
};

int main()
{
    double sum = 0.0;
    ifstream inputFile;
    list<Payments> paymentList;
    FileProcessing fileProcessing;

    fileProcessing.getDataFile(inputFile, paymentList);

    for (const Payments payment : paymentList)
    {
        cout << payment.name << " -> " << payment.paymentAmount << endl;
        sum += payment.paymentAmount;
    }

    cout << "Sum: " << sum << endl;

    return 0;
}
