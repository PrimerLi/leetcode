#include <iostream>
#include <string>
using namespace std;

int longestPalindrome(string s)
{
    int result = 0;
    int len = s.length();
    bool table[len][len];
    for (int i = 0; i < len; ++i)
        table[i][i] = true;
    for (int i = 0; i< len-1; ++i)
    {
        table[i][i+1] = (s[i] == s[i+1]);
    }
    for (int i = len-2; i >= 0; --i)
    {
        for (int j = i+1; j < len; ++j)
        {
            table[i][j] = (s[i] == s[j])&&table[i+1][j-1];
        }
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = i; j < len; ++j)
        {
            if (table[i][j])
            {
                result = max(result, j-i+1);
            }
        }
    }
    return result;
}

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return s;
        bool table[len][len];
        int maxLen = 0;
        for (int i = 0; i < len; ++i)
        {
            table[i][i] = true;
        }
        for (int i = len-2; i >= 0; i--)
        {
            for (int j = i+1; j < len; ++j)
            {
                if (i+1 <= j-1) table[i][j] = (s[i]==s[j])&&table[i+1][j-1];
                else table[i][j] = (s[i] == s[j]);
            }
        }
        
        maxLen = 0;
        int start, end;
        for (int i = 0; i < len; ++i)
        {
            for (int j = i; j < len; ++j)
            {
                if (table[i][j] && j-i+1 > maxLen)
                {
                    maxLen = j-i+1;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


int main()
{
    string s = "aabbddccffeegg";
    Solution sol;
    string result = sol.longestPalindrome(s);
    cout << result << endl;
    return 0;
}
