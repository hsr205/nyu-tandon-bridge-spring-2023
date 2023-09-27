#include "Organism.h"
#include <iostream>

class Ant : public Organism
{
private:
public:
    Ant();

    void move() override
    {
        std::cout << "The ANT is moving. " << std::endl;
    };
    void breed() override
    {
        std::cout << "The ANT is breeding. " << std::endl;
    };
};

