#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct data
{
    int start;
    int end;
    int product;
    data(){}
    data(int s, int e, int p) : start(s), end(e), product(p) {}
};

data maxProduct(const vector<int> &numbers, int low, int high)
{
    assert(low >= 0);
    assert(high > low);
    int size = numbers.size();
    assert(size > 0);
    assert(size >= high);
    if (low == high-1) return data(low, high, numbers[low]);
    if (low == high-2)
    {
        int a = numbers[low];
        int b = numbers[low+1];
        int p = a*b;
        int result = a;
        result = max(result, b);
        result = max(result, p);
        if (result == a)
        {
            return data(low, low+1, result);
        }
        else if (result == b)
        {
            return data(low+1, high, result);
        }
        else
        {
            return data(low, high, result);
        }
    }
    int mid = (low + high)/2;
    //cout << low << "  " << mid << "  " << high << endl;
    data leftData = maxProduct(numbers, low, mid);
    data rightData = maxProduct(numbers, mid, high);

    int leftMinIndex, leftMaxIndex;
    int leftProduct = 1;
    int leftMax, leftMin;
    leftMax = INT_MIN;
    leftMin = INT_MAX;
    for (int i = mid-1; i >= low; --i)
    {
        leftProduct = leftProduct*numbers[i];
        if (leftMax < leftProduct)
        {
            leftMax = leftProduct;
            leftMaxIndex = i;
        }
        if (leftMin > leftProduct)
        {
            leftMin = leftProduct;
            leftMinIndex = i;
        }
    }
    
    int rightMinIndex, rightMaxIndex;
    int rightProduct = 1;
    int rightMax, rightMin;
    rightMax = INT_MIN;
    rightMin = INT_MAX;
    for (int i = mid; i < high; ++i)
    {
        rightProduct = rightProduct*numbers[i];
        if (rightProduct > rightMax)
        {
            rightMax = rightProduct;
            rightMaxIndex = i;
        }
        if (rightProduct < rightMin)
        {
            rightMin = rightProduct;
            rightMinIndex = i;
        }
    }
    
    int crossProduct;
    int leftIndex, rightIndex;
    crossProduct = leftMin*rightMin;
    crossProduct = max(crossProduct, leftMax*rightMax);
    if (crossProduct == rightMin*leftMin)
    {
        leftIndex = leftMinIndex;
        rightIndex = rightMinIndex;
    }
    else
    {
        leftIndex = leftMaxIndex;
        rightIndex = rightMaxIndex;
    }
    
    int result = crossProduct;
    result = max(result, leftData.product);
    result = max(result, rightData.product);
    if (result == crossProduct)
    {
        return data(leftIndex, rightIndex, result);
    }
    else if (result == leftData.product)
    {
        return leftData;
    }
    else
    {
        return rightData;
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

int dp(const vector<int> &numbers)
{
    int size = numbers.size();
    assert(size > 0);
    int maxValue, minValue;
    int result = numbers[0];
    maxValue = minValue = result;
    for (int i = 1; i < size; ++i)
    {
        if (numbers[i] < 0)
        {
            int temp = maxValue;
            maxValue = minValue;
            minValue = temp;
        }
        maxValue = max(maxValue*numbers[i], numbers[i]);
        minValue = min(minValue*numbers[i], numbers[i]);
        result = max(result, maxValue);
    }
    return result;
}

int main()
{
    vector<int> numbers;
    int len = 10;
    int mod = 2*len;
    for (int i = 0; i < len; ++i)
    {
        numbers.push_back(rand()%mod - mod/2);
    }
    printVector(numbers);
    data result = maxProduct(numbers, 0, len);
    cout << result.start << "  " << result.end << "  " << result.product << endl;
    cout << dp(numbers) << endl;
    return 0;
}
