#include <iostream>
#include "Ant.h"
#include "Organism.h"
#include "DoodleBug.h"

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

    delete ant;
    delete doodleBug;

    return 0;
}
