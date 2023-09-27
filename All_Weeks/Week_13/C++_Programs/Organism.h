#ifndef ORGANISM_H
#define ORGANISM_H

class Organism
{

public:
    Organism();
    virtual ~Organism();

    virtual void move(){};

    virtual void breed(){};
};

#endif