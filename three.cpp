#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int two(const vector<int> &numbers, int target)
{
    int size = numbers.size();
    assert(size >= 2);
    int result = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i+1; j < size; ++j)
        {
            if (numbers[i] + numbers[j] == target)
                result++;
        }
    }
    return result;
}

int three(const vector<int> &numbers)
{
    int size = numbers.size();
    assert(size >= 3);
    if (size == 3) 
    {
        int s = 0;
        for (int i = 0; i < size; ++i)
            s = s + numbers[i];
        if (s == 0) return 1;
        return 0;
    }
    else
    {
        int result = 0;
        vector<int> tail(numbers.begin() + 1, numbers.end());
        result = three(tail);
        int temp = two(tail, -numbers[0]);
        return temp + result;
    }
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}

int main()
{
    vector<int> numbers;
    int len = 200;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%(4*len) - 2*len);
    }
    //printVector(numbers);
    cout << three(numbers) << endl;
    return 0;
}
