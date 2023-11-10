#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Vehicle
{

private:
    double toll = 0;
    double total = 0.0;

public:
    Vehicle() = default;
    ~Vehicle() = default;

    void incurToll(double tollValue)
    {
        total += tollValue;
    };

    virtual double getToll() = 0;

    virtual double getTollTotal() = 0;
};

class Car : public Vehicle
{

private:
    double toll = 5.0;
    double total = 5.0;

public:
    Car() = default;
    ~Car() = default;

    friend Vehicle;

    double getToll() override
    {
        return toll;
    }

    double getTollTotal() override
    {
        return total;
    };
};

class Truck : public Vehicle
{

private:
    double toll = 25.0;
    double total = 25.0;

public:
    Truck() = default;
    ~Truck() = default;

    double getToll() override
    {
        return toll;
    }

    double getTollTotal() override
    {
        return total;
    };

};

template <typename T>
class TollBooth
{

private:
    double total = 0.0;

public:
    TollBooth() = default;
    ~TollBooth() = default;

    void processToll(T &vehicle)
    {
        total += vehicle.getToll();

        vehicle.incurToll(total);
    }

    double getTotalToll()
    {
        return total;
    }
};

void truckTest1()
{
    Truck truck1;
    TollBooth<Vehicle> tollBooth1;
    tollBooth1.processToll(truck1);
    tollBooth1.processToll(truck1);

    double truck1Total = tollBooth1.getTotalToll();

    cout << "The total for truck1 is: " << truck1Total << endl;
}

void carTest1()
{

    Car car1;
    Truck truck1;
    TollBooth<Vehicle> tollBooth1;

    tollBooth1.processToll(car1);
    tollBooth1.processToll(car1);

    double car1Total = tollBooth1.getTotalToll();

    cout << "The total for car1 is: " << car1Total << endl;
}

void truckTest2()
{
    Truck truck2;
    TollBooth<Vehicle> tollBooth2;
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);
    tollBooth2.processToll(truck2);

    double truck1Total = tollBooth2.getTotalToll();

    cout << "The total for truck2 is: " << truck1Total << endl;
}

void carTest2()
{

    Car car2;
    TollBooth<Vehicle> tollBooth2;

    tollBooth2.processToll(car2);
    tollBooth2.processToll(car2);
    tollBooth2.processToll(car2);
    tollBooth2.processToll(car2);

    double car1Total = tollBooth2.getTotalToll();

    cout << "The total for car2 is: " << car1Total << endl;
}

void truckTest3()
{
    Truck truck3;
    TollBooth<Vehicle> tollBooth3;
    tollBooth3.processToll(truck3);

    double truck1Total = tollBooth3.getTotalToll();

    cout << "The total for truck3 is: " << truck1Total << endl;
}

void carTest3()
{

    Car car3;
    TollBooth<Vehicle> tollBooth3;

    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);
    tollBooth3.processToll(car3);

    double car1Total = tollBooth3.getTotalToll();

    cout << "The total for car3 is: " << car1Total << endl;
}

int main()
{

    carTest1();
    carTest2();
    carTest3();

    truckTest1();
    truckTest2();
    truckTest3();

    return 0;
}
