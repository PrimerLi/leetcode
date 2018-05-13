#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> sort(vector<string> str)
    {
        if (str.size() == 0 || str.size() == 1) return str;
        vector<string> lower, upper, equal;
        int pivot = str[0].length();
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i].length() < pivot) lower.push_back(str[i]);
            else if(str[i].length() == pivot) equal.push_back(str[i]);
            else upper.push_back(str[i]);
        }
        lower = sort(lower);
        upper = sort(upper);
        vector<string> result;
        /*for (int i = 0; i < lower.size(); ++i)
            result.push_back(lower[i]);
        for (int i = 0; i < equal.size(); ++i)
        {
            result.push_back(equal[i]);
        }
        for (int i = 0; i < upper.size(); ++i)
        {
            result.push_back(upper[i]);
        }*/
        result.insert(result.end(), lower.begin(), lower.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), upper.begin(), upper.end());
        return result;
    }
    
    pair<int, int> getStat(const string &str)
    {
        int nz, n_one;
        nz = 0;
        n_one = 0;
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == '0') nz++;
            else n_one++;
        }
        return pair<int, int>(nz, n_one);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        strs = sort(strs);
        int count = 0;
        int currentZero = m;
        int currentOne = n;
        for (int i = 0;  i < strs.size(); ++i)
        {
           	pair<int, int> stat = getStat(strs[i]);
            if (currentZero >= stat.first && currentOne >= stat.second)
            {
                count++;
                currentZero = currentZero - stat.first;
                currentOne = currentOne - stat.second;
            }
            else break;
        }
        return count;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("10");
    strs.push_back("0001");
    strs.push_back("111001");
    strs.push_back("1");
    strs.push_back("0");
    Solution s;
    strs = s.sort(strs);
    for (int i = 0; i < strs.size(); ++i)
    {
        cout << strs[i] << endl;
    }
    return 0;
}
