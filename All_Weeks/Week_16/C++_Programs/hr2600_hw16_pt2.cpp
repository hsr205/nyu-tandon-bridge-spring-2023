#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Queue
{

private:
    int index = 0;
    vector<T> dataVector;

public:
    Queue() = default;
    ~Queue() = default;

    int front() const
    {
        return dataVector[index];
    }

    void enqueue(T newValue)
    {
        dataVector.push_back(newValue);
    }

    void dequeue()
    {
        dataVector.erase(dataVector.begin());
    }

    bool isEmpty()
    {
        return dataVector.size() == 0;
    }

    int size()
    {
        if (isEmpty())
        {
            dataVector.resize(1);
        }

        return dataVector.size();
    }
};
