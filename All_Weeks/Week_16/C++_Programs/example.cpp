#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    vector<int> testVector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int sum = accumulate(testVector.begin(), testVector.end(), 0);

    cout << "Sum: " << sum << endl;

    return 0;
}
