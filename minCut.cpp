#include <iostream>
#include <cstring>
using namespace std;

int minCut(string s) {
    int len = s.length();
    if (len == 0 || len == 1) return 0;
    bool table[len][len];
    for (int i = 0; i < len; ++i)
    {
        table[i][i] = true;
    }
    
    for (int i = len-2; i >= 0; i--)
    {
        for (int j = i+1; j < len; ++j)
        {
            if (i+1 <= j-1) table[i][j] = table[i+1][j-1]&&(s[i] == s[j]);
            else table[i][j] = (s[i] == s[j]);
        }
    }
    
    int start, end;
    int maxLen = 0;
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
    
    cout << start << "  " << end << "  " << maxLen << endl;
    cout << s << endl;
    if (maxLen == 1) return len-1;
    if (start == 0 && maxLen == len) return 0;
    else if (start == 0 && maxLen < len)
    {
        return 1 + minCut(s.substr(end+1, len - maxLen));
    }
    else if (end == len-1)
    {
        return 1 + minCut(s.substr(start, len-maxLen));
    }
    else
    {
        return 1 + minCut(s.substr(0, start) + s.substr(end+1, len-start-maxLen));
    }
}


int main()
{
    string s = "caabbddccffeeggk";
    cout << minCut(s) << endl;
    return 0;
}