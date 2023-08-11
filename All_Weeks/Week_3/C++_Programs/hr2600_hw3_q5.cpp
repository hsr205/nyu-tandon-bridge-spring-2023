#include <iostream>

using namespace std;

int main()
{
    const double KILOGRAMS = 0.453592;
    const double METERS = 0.0254;
    const double UNDER_WEIGHT = 18.5;
    const double NORMAL_WEIGHT = 25.0;
    const double OVER_WEIGHT = 30.0;
    int weightInLbs;
    int heightInInches;
    double totalKilograms;
    double totalMeters;
    double bmi;

    cout << "Please enter weight(in pounds): ";
    cin >> weightInLbs;

    cout << "Please enter heights(in inches): ";
    cin >> heightInInches;

    cout << "weightInLbs: "<< weightInLbs << endl;
    cout << "heightInInches: "<< heightInInches << endl;

    totalKilograms = weightInLbs * KILOGRAMS;
    totalMeters = heightInInches * METERS;
    bmi = totalKilograms / pow(totalMeters, 2);

    cout << "totalKilograms: "<< totalKilograms << endl;
    cout << "totalMeters: "<< totalMeters << endl;
    cout << "bmi: "<< bmi << endl;


    if (bmi < UNDER_WEIGHT)
    {
        cout << "The weight status is: Underweight" << endl;
    }
    else if (bmi >= UNDER_WEIGHT && bmi < NORMAL_WEIGHT)
    {
        cout << "The weight status is: Normal" << endl;
    }
    else if (bmi >= NORMAL_WEIGHT && bmi <= OVER_WEIGHT)
    {
        cout << "The weight status is: Overweight" << endl;
    }
        else if (bmi > OVER_WEIGHT)
    {
        cout << "The weight status is: Obese" << endl;
    }

    return 0;
}