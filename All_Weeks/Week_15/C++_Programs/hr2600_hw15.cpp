#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

class Employee
{

private:
    int id;
    double hourlyPay;
    string name;

public:
    Employee(int id = 0, double hourlyPay = 0.0, string name = "None")
        : id(id), hourlyPay(hourlyPay), name(name){};

    ~Employee() = default;

    int getId() const
    {
        return id;
    }

    double getHourlyPay() const
    {
        return hourlyPay;
    }
    string getName() const
    {
        return name;
    }

    void setId(int newId)
    {
        id = newId;
    }

    void setHourlyPay(double newHourlyPay)
    {
        hourlyPay = newHourlyPay;
    }

    void setName(string newName)
    {
        name = newName;
    }
};

class FileProcessing
{

private:
    Employee employee;

    void openInputFile(ifstream &inputFile)
    {
        string filePath;

        cout << "What is the file name (file path): " << endl;
        cin >> filePath;
        inputFile.open(filePath);

        while (!inputFile)
        {
            cout << "File Failed to Open" << endl;
            cout << "What is the file name (file path): " << endl;
            cin >> filePath;
            inputFile.clear();
            inputFile.open(filePath);
        }
    }

public:
    FileProcessing(){};

    ~FileProcessing() = default;

    vector<Employee> getEmployeeVector(ifstream &inputFile)
    {
        openInputFile(inputFile);

        int id;
        double hourlyPay;
        string name;
        vector<Employee> employeeVector;

        while (inputFile >> id >> hourlyPay)
        {
            Employee employee;

            getline(inputFile, name);

            employee.setId(id);
            employee.setHourlyPay(hourlyPay);
            employee.setName(name);

            employeeVector.push_back(employee);
        }

        inputFile.close();

        return employeeVector;
    }
};


/*
    (1) Now read in the data from the payroll.txt file
*/
int main()
{

    Employee employee;
    ifstream inputFile;
    FileProcessing fileProcessing;

    vector<Employee> employeeVector = fileProcessing.getEmployeeVector(inputFile);

    for (const Employee &employee : employeeVector)
    {
        cout << string(30, '=') << endl;
        cout << "Id: " << employee.getId() << endl;
        cout << "Hourly Pay: " << employee.getHourlyPay() << endl;
        cout << "Name: " << employee.getName() << endl;
    }

    cout << string(30, '=') << endl;

    return 0;
}
