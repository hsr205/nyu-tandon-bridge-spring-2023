#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"

class DoodleBug : public Organism
{
public:
    // DoodleBug();
    // ~DoodleBug();
    void move() override;
    void breed() override;
    void starve();
};

#endif