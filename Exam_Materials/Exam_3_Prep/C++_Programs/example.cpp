#include <iostream>
#include <vector>

using namespace std;

class Furniture
{

private:
public:
    Furniture() = default;
    ~Furniture() = default;
    virtual void display() = 0;
};

class Chair : public Furniture
{

private:
public:
    Chair() = default;
    ~Chair() = default;
    void display() override
    {
    }
};

int main()
{

    Chair *chair1;
    Chair *chair2;
    Chair *chair3;

    vector<Furniture *> furnitureVector;

    furnitureVector.push_back(chair1);
    furnitureVector.push_back(chair2);
    furnitureVector.push_back(chair3);

    return 0;
}
