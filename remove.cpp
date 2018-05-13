#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> reduceDuplicates(vector<int> &numbers)
{
    unordered_map<int, int> map;
    int size = numbers.size();
    if (size == 0) return numbers;
    for (int i = 0; i < size; ++i)
    {
        map[numbers[i]] += 1;
    }

    vector<int> result;
    for (auto e : map)
    {
        result.push_back(e.first);
    }
    sort(result.begin(), result.end());
    return result;
}

vector<int> removeDuplicates(vector<int> &numbers)
{
    vector<int> result;
    unordered_map<int, int> map;
    for (int i = 0; i < numbers.size(); ++i)
    {
        map[numbers[i]] = map[numbers[i]] + 1;
    }

    for (auto ele : map)
    {
        if (ele.second == 1) result.push_back(ele.first);
    }
    sort(result.begin(), result.end());
    return result;
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> numbers;
    int len = 20;
    int mod = len;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%mod);
    }
    sort(numbers.begin(), numbers.end());
    printVector(numbers);
    vector<int> result = reduceDuplicates(numbers);
    printVector(result);
    result = removeDuplicates(numbers);
    printVector(result);
    return 0;
}
