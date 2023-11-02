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

int main()
{

    Queue<int> dataQueue;

    dataQueue.enqueue(1);
    dataQueue.enqueue(2);
    dataQueue.enqueue(3);
    dataQueue.enqueue(4);
    dataQueue.enqueue(5);

    cout << "Size: " << dataQueue.size() << endl;

    dataQueue.dequeue();
    dataQueue.dequeue();
    dataQueue.dequeue();
    dataQueue.dequeue();
    dataQueue.dequeue();

    cout << "Size: " << dataQueue.size() << endl;

    // while (!dataQueue.isEmpty())
    // {

    //     cout << "Element: " << dataQueue.front() << endl;
    //     dataQueue.dequeue();
    // }

    return 0;
}
