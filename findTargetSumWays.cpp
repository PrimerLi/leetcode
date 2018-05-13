#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    string ptos(int index, int sum)
    {
        return to_string(index) + ", " + to_string(sum);
    }
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int MAXSUM = 1000;
        if (S > MAXSUM) return 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            temp = temp + nums[i];
        }
        MAXSUM = temp;
        cout << MAXSUM << endl;
        int size = nums.size();
        unordered_map<string, int> map;
        for (int s = -S; s <= S; ++s)
        {
            string p("0, " + to_string(s));
            if (s == 0) map[p] = (nums[0] == 0)? 2 : 0;
            else map[p] = (nums[0] == -s || nums[0] == s)? 1 : 0;
        }
        for (int i = 1; i < size; ++i)
        {
            for (int s = -MAXSUM; s <= MAXSUM; ++s)
            {
                string stemp = ptos(i, s);
                map[stemp] = map[ptos(i-1, s-nums[i])] + map[ptos(i-1, s+nums[i])];
            }
        }
        return map[ptos(size-1, S)];
        return 0;
    }
};

int main()
{
    Solution s;
    int a[] = {9,28,50,9,34,48,2,50,38,10,5,16,44,5,48,21,38,17,21,49};
    int len = sizeof(a)/sizeof(a[0]);
    vector<int> nums;
    for (int i = 0; i < len; ++i)
        nums.push_back(a[i]);
    int target = 20;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}
