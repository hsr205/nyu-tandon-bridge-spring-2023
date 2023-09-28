#include <iostream>
#include <map>

using namespace std;

class Organism
{

public:
    Organism(){};

    virtual void move(){};
    virtual void breed(){};
};

class Ant : public Organism
{
private:
    map<int, int> positionMap;

public:
    // Ant();
    // ~Ant();
    void move() override
    {
        cout << "Ant is moving." << endl;
    }

    void breed() override
    {
        cout << "Ant is breeding." << endl;
    }
};

class DoodleBug : public Organism
{
    // private:
    //     map<int, int> positionMap;

public:
    // DoodleBug();
    // ~DoodleBug();
    void move() override
    {
        cout << "DoodleBug is moving." << endl;
    }

    void breed() override
    {
        cout << "DoodleBug is breeding." << endl;
    }
    void starve()
    {
        cout << "DoodleBug is starving." << endl;
    }
};

int main()
{

    Ant *ant = new Ant();
    DoodleBug *doodleBug = new DoodleBug();

    ant->move();
    ant->breed();

    cout << "----------------------------------" << endl;

    doodleBug->move();
    doodleBug->breed();
    doodleBug->starve();

    delete ant;
    delete doodleBug;

    return 0;
}
