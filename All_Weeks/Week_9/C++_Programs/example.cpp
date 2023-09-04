#include <iostream>

using namespace std;

void pointerExample()
{

    int intValue = 2;

    int *ptr = &intValue;

    // Output: 2
    cout << "intValue: " << intValue << endl;
    
    // Output: Memory location of intValue
    cout << "&intValue: " << &intValue << endl;
    cout << "---------------------------------" << endl;

    // Output: Memory location of intValue
    cout << "ptr: " << ptr << endl;

    // Output: Memory location of ptr
    cout << "&ptr: " << &ptr << endl;

    // Output: 2
    cout << "*ptr: " << *ptr << endl;
}

int main()
{

    pointerExample();
    return 0;
}
