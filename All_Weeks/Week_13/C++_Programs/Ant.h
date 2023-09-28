#ifndef ANT_H
#define ANT_H

#include "Organism.h"

class Ant : public Organism
{
public:
    // Ant();
    // ~Ant();
    void move() override;
    void breed() override;
};

#endif