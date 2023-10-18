#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <map>

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

class EmployeePayRoll
{

private:
    int id;
    double hoursWorked;

public:
    EmployeePayRoll(int id = 0, double hoursWorked = 0.0)
        : id(id), hoursWorked(hoursWorked){};

    ~EmployeePayRoll() = default;

    int getId() const
    {
        return id;
    }

    double getHoursWorked() const
    {
        return hoursWorked;
    }

    void setId(int newId)
    {
        id = newId;
    }

    void setHoursWorked(double newHoursWorked)
    {
        hoursWorked = newHoursWorked;
    }
};

class FileProcessing
{

private:
    Employee employee;
    EmployeePayRoll employeePayRoll;

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

    list<Employee> getEmployeeData(ifstream &inputFile)
    {
        openInputFile(inputFile);

        int id;
        double hourlyPay;
        string name;
        list<Employee> employeeList;

        while (inputFile >> id >> hourlyPay)
        {
            Employee employee;

            getline(inputFile, name);

            employee.setId(id);
            employee.setHourlyPay(hourlyPay);
            employee.setName(name);

            employeeList.push_back(employee);
        }

        inputFile.close();

        return employeeList;
    }

    list<EmployeePayRoll> getEmployeePayRollData(ifstream &inputFile)
    {
        openInputFile(inputFile);

        int id;
        int hoursWorked;
        list<EmployeePayRoll> employeeList;

        while (inputFile >> id >> hoursWorked)
        {
            EmployeePayRoll employeePayRoll;

            employeePayRoll.setId(id);
            employeePayRoll.setHoursWorked(hoursWorked);

            employeeList.push_back(employeePayRoll);
        }

        inputFile.close();

        return employeeList;
    }
};

struct AllEmployeeData
{
    int id;
    bool isDuplicate;
    double hoursWorked;
    double hourlyPay;
    double totalPay;
    string name;
};

int main()
{

    Employee employee;
    ifstream inputFile;
    FileProcessing fileProcessing;
    EmployeePayRoll employeePayRoll;
    vector<AllEmployeeData> allEmployeeDataVector;

    list<Employee> employeeList = fileProcessing.getEmployeeData(inputFile);
    list<EmployeePayRoll> employeePayRollList = fileProcessing.getEmployeePayRollData(inputFile);

    for (const Employee &employee : employeeList)
    {

        for (const EmployeePayRoll &employeePayRoll : employeePayRollList)
        {

            AllEmployeeData employeeData;

            if (employee.getId() == employeePayRoll.getId())
            {
                // cout << "Id: " << employee.getId() << endl;
                employeeData.id = employee.getId();
                employeeData.name = employee.getName();
                employeeData.hourlyPay = employee.getHourlyPay();
                employeeData.hoursWorked = employeePayRoll.getHoursWorked();
                employeeData.totalPay = employee.getHourlyPay() * employeePayRoll.getHoursWorked();
            }

            else
            {
                employeeData.name = "Duplicate";
            }

            allEmployeeDataVector.push_back(employeeData);
        }
    }

    map<string, double> resultMap;

    for (const AllEmployeeData &employee : allEmployeeDataVector)
    {
        if (employee.name != "Duplicate")
        {
            resultMap[employee.name] += employee.totalPay;
        }
    }

    cout << endl;

    cout << string(9, '*') << "Payroll Information" << string(8, '*') << endl;
    /*
    // TODO: 
        (1) Find a simple way to sort the map by value in descending order
        (2) Abstract most of the implementations in the main method into separate classes
    */

    for (const auto &keyValue : resultMap)
    {
        cout << keyValue.first << ", $" << keyValue.second << endl;
    }

    cout << string(9, '*') << "End Payroll" << string(14, '*') << endl;

    return 0;
}
