#include <vector>
#include <iostream>
using namespace std;

vector<int> merge(vector<int> &front, vector<int> &back)
{
    vector<int> result;
    if (front.size() == 0) return back;
    if (back.size() == 0) return front;
    int i = 0;
    int j = 0;
    while(true)
    {
        if (front[i] < back[j])
        {
            result.push_back(front[i]);
            i++;
            if (i == front.size()) break;
        }
        else
        {
            result.push_back(back[j]);
            j++;
            if (j == back.size()) break;
        }
    }
    for (int k = i; k < front.size(); ++k)
    {
        result.push_back(front[k]);
    }
    for (int k = j; k < back.size(); ++k)
    {
        result.push_back(back[k]);
    }
    return result;
}

vector<int> mergesort(vector<int> &nums)
{
    int size = nums.size();
    if (size == 0 || size == 1) return nums;
    vector<int> front, back;
    front.insert(front.end(), nums.begin(), nums.begin() + size/2);
    back.insert(back.end(), nums.begin() + size/2, nums.end());
    front = mergesort(front);
    back = mergesort(back);
    vector<int> result = merge(front, back);
    return result;
}

void printVector(const vector<int> &nums)
{
    for (int i = 0; i < nums.size(); ++i)
    {
        cout << nums[i] << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums;
    int len = 200;
    int mod = 4*len;
    for (int i = 0; i < len; ++i)
    {
        nums.push_back(rand()%mod);
    }
    printVector(nums);
    vector<int> result = mergesort(nums);
    printVector(result);
    return 0;
}
