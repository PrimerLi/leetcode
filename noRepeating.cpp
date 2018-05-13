#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool contains(string s, char c)
{
    int len = s.length();
    if (len == 0) return false;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == c) return true;
    }
    return false;
}

int noRepeating(string s)
{
    int len = s.length();
    if (len == 0 || len == 1) return len;
    bool table[len][len];
    for (int i = 0; i < len; ++i)
    {
        table[i][i] = true;
    }
    for (int i = 0; i < len-1; ++i)
    {
        table[i][i+1] = (s[i] != s[i+1]);
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            table[i][j] = table[i][j-1]&&(!contains(s.substr(i, j-i), s[j]));
        }
    }

    int maxLen = 0;
    int start, end;
    for (int i = 0; i < len; ++i)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (table[i][j] && j-i+1 > maxLen)
            {
                start = i;
                end = j;
                maxLen = j-i+1;
            }
        }
    }
    cout << s.substr(start, maxLen) << endl;
    return maxLen;
}

int longest(string s)
{
    int len = s.length();
    vector<int> map(256, -1);
    int start = -1;
    int maxLen = 0;
    int end = -1;
    for (int i = 0; i < len; ++i)
    {
        if (map[s[i]] > start) start = map[s[i]];
        map[s[i]] = i;
        if (i-start > maxLen)
        {
            maxLen = i-start;
            end = i;
        }
    }
    cout << s.substr(end+1-maxLen, maxLen) << endl;
    return maxLen;
}

int main()
{
    string s = "abczxccabcbb";
    cout << longest(s) << endl;
    return 0;
}
