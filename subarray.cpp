#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct data
{
    int start;
    int end;
    int sum;
    data(int s, int e, int summation) : start(s), end(e), sum(summation){}
    data(){}
};

data maxsubarray(const vector<int> &numbers, int low, int high)
{
    int size = numbers.size();
    int leftSum, rightSum;
    int crossSum;
    int mid = (low + high + 1)/2;
    //cout << low << "  " << mid << "  " << high << endl;
    assert(low <= mid);
    assert(mid <= high);
    assert(low >= 0);
    assert(high <= size-1);
    if (high == low)
    {
        return data(low, low, numbers[low]);
    }
    if (high - low == 1)
    {
        int s = numbers[low];
        s = max(s, numbers[high]);
        s = max(s, numbers[low] + numbers[high]);
        if (s == numbers[low]) return data(low, low, s);
        else if (s == numbers[high]) return data(high, high, s);
        else return data(low, high, s);
    }
    data leftData = maxsubarray(numbers, low, mid);
    data rightData = maxsubarray(numbers, mid+1, high);
    leftSum = INT_MIN;
    int sum = 0;
    int leftIndex = 0;
    int rightIndex = 0;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + numbers[i];
        if (sum > leftSum)
        {
            leftSum = sum;
            leftIndex = i;
        }
    }
    sum = 0;
    rightSum = INT_MIN;
    for (int i = mid+1; i <= high; ++i)
    {
        sum = sum + numbers[i];
        if (sum > rightSum)
        {
            rightSum = sum;
            rightIndex = i;
        }
    }
    crossSum = leftSum + rightSum;
    data result;
    int maxSum = leftData.sum;
    maxSum = max(maxSum, crossSum);
    maxSum = max(maxSum, rightData.sum);
    if (maxSum == leftData.sum)
    {
        return leftData;
    }
    else if (maxSum == rightData.sum)
    {
        return rightData;
    }
    else
    {
        result.start = leftIndex;
        result.end = rightIndex;
        result.sum = crossSum;
        return result;
    }
}

data maxsubarray(const vector<int> &numbers)
{
    int low = 0;
    int high = numbers.size()-1;
    int mid = (low + high + 1)/2;
    data result = maxsubarray(numbers, low, high);
    return result;
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << ", ";
    }
    cout << endl;
}

void printVector(const vector<int> &numbers, int low, int high)
{
    int size = numbers.size();
    int sum = 0;
    assert(low >= 0);
    assert(high <= size-1);
    assert(low <= high);
    for (int i = low; i <= high; ++i)
    {
        cout << numbers[i] << "  ";
        sum = sum + numbers[i];
    }
    cout << "sum = " << sum << endl;
    cout << endl;
}

int maxsubarraydp(const vector<int> &numbers)
{
    int size = numbers.size();
    assert(size > 0);
    int table[size];
    table[0] = numbers[0];
    int result = table[0];
    for (int i = 1; i < size; ++i)
    {
        table[i] = max(numbers[i], table[i-1] + numbers[i]);
        result = max(result, table[i]);
    }
    int index = 0;
    result = table[0];
    for (int i = 0; i < size; ++i)
    {
        if (table[i] > result)
        {
            index = i;
            result = table[i];
        }
    }
    cout << index << endl;
    return result;
}

int main()
{
    vector<int> numbers;
    int len = 23;
    int mod = 4*len;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%(mod) - mod/2);
    }
    printVector(numbers);
    data result = maxsubarray(numbers);
    printVector(numbers, result.start, result.end);
    cout << result.start << "  " << result.end << "  " << result.sum << endl;
    cout << maxsubarraydp(numbers) << endl;
    return 0;
}
