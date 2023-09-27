#include "Organism.h"
#include <iostream>

class DoodleBug : public Organism
{
private:
public:
    DoodleBug();

    void move() override
    {
        std::cout << "The DoodleBug is moving. " << std::endl;
    };
    void breed() override
    {
        std::cout << "The DoodleBug is breeding. " << std::endl;
    };

    void starve()
    {
        std::cout << "The DoodleBug has starved. " << std::endl;
    };
};
