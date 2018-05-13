#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(const vector<int> &numbers)
{
    int size = numbers.size();
    int table[size];
    table[0] = numbers[0];
    int result = table[0];
    for (int i = 1; i < size; ++i)
    {
        if (table[i-1] > 0) table[i] = table[i-1] + numbers[i];
        else table[i] = numbers[i];
        result = max(result, table[i]);
    }
    return result;
}

int main()
{
    vector<int> numbers;
    int len = 20;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%(4*len) - 2*len);
    }
    for (int i = 0; i < numbers.size(); ++i)
        cout << numbers[i] << ", ";
    cout << endl;
    cout << maxSubarray(numbers) << endl;
    return 0;
}
