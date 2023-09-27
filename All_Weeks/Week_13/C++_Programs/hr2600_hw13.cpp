#include <iostream>
#include "Ant.cpp"
#include "Organism.h"
#include "DoodleBug.cpp"

using namespace std;

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

    return 0;
}
