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

    void push(T newValue)
    {
        dataVector.push_back(newValue);
    }

    void pop()
    {
        ++index;
        dataVector.insert(dataVector.begin(), dataVector.begin() + index, dataVector.begin() + dataVector.size());
    }

    bool isEmpty()
    {
        return dataVector.size() == 0;
    }

    void resetVector()
    {
        if (isEmpty(dataVector))
        {
            dataVector.resize(1);
        }
    }
};

int main()
{

    Queue<int> dataQueue;

    dataQueue.push(3);

    while(!dataQueue.isEmpty()){



    }

    return 0;
}
