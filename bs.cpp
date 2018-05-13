#include <vector>
#include <iostream>
using namespace std;

int find(const vector<int> &array, int target)
{
    int start, end, mid;
    start = 0;
    end = array.size(); 
    mid = (start + end)/2;
    if (array.size() == 0) return -1;
    while(start <= end)
    {
        if (target < array[mid])
        {
            end = mid-1;
            mid = (start + end)/2;
        }
        else if (target > array[mid])
        {
            start = mid+1;
            mid = (start + end)/2;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main()
{
    vector<int> array;
    int len = 10;
    for (int i = 0; i < len; ++i)
    {
        array.push_back(i);
    }
    int index = find(array, -120);
    cout << index << endl;
    return 0;
}
