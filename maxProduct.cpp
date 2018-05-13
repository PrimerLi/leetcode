#include <iostream>
#include <vector>
using namespace std;

int maxProduct(const vector<int> &nums)
{
    int size = nums.size();
    if (size == 0) return 0;
    int imax, imin, result;
    result = nums[0];
    imax = result;
    imin = result;
    for (int i = 1; i < size; ++i)
    {
        if (nums[i] < 0)
        {
            int temp = imax;
            imax = imin;
            imin = temp;
        }
        imax = max(imax*nums[i], nums[i]);
        imin = min(imin*nums[i], nums[i]);
        cout << "i = " << i << ", max = " << imax << ", min = " << imin << endl;
        result = max(result, imax);
    }
    return result;
}

int main()
{
    vector<int> nums;
    int len = 9;
    int a[] = {5, -9, -9, -87, -2, 0, -10, 4, -7};
    for (int i = 0; i < len; ++i)
        nums.push_back(a[i]);
    int result = maxProduct(nums);
    cout << result << endl;
    return 0;
}
