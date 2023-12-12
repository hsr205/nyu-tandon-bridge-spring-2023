#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Clothing
{

private:
    string description;
    bool isOwned;

public:
    Clothing(string newDescription, bool newBoolValue)
    {
        description = newDescription;
        isOwned = newBoolValue;
    }
    Clothing() = default;

    string getDescription()
    {
        return description;
    }

    bool getIsOwned()
    {
        return isOwned;
    }
};

class Person
{

private:
    string name;
    vector<Clothing> clothingVector;

public:
    Person(string newName)
    {
        name = newName;
    }

    Person()
    {
        name = "Jane Doe";
    };

    void addClothing(Clothing clothingItem)
    {
        clothingVector.push_back(clothingItem);
    }

    void removeClothingItem(Clothing clothingItem)
    {
        
    }

    // void tradeClothing(Clothing *owner, Clothing *partner)
    // {

    // }

    bool purchaseClothing(Clothing clothing)
    {
        if (!clothing.getIsOwned())
        {
            return true;
        }

        return false;
    }

    vector<Clothing> getClothingVector()
    {
        return clothingVector;
    }

    string getName()
    {
        return name;
    }
};

int main()
{
    Person person1;
    Person person2 = Person("Henry Rothenberg");

    Clothing shirt = Clothing("Shirt", true);
    Clothing pants = Clothing("Pants", true);
    Clothing hat = Clothing("Hat", true);

    Clothing shoes = Clothing("Shoes", true);
    Clothing glasses = Clothing("Glasses", true);
    Clothing socks = Clothing("Socks", true);

    person1.addClothing(shoes);
    person1.addClothing(glasses);
    person1.addClothing(socks);

    person2.addClothing(shirt);
    person2.addClothing(pants);
    person2.addClothing(hat);

    vector<Clothing> person2ClothingVector = person2.getClothingVector();

    // for (Clothing item : person2ClothingVector)
    // {
    //     cout << "Clothing item: " << item.getDescription() << endl;
    // }

    vector<Clothing> person1ClothingVector = person1.getClothingVector();

    // for (Clothing item : person1ClothingVector)
    // {
    //     cout << "Clothing item: " << item.getDescription() << endl;
    // }

    return 0;
}