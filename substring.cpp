#include <string>
#include <iostream>
using namespace std;

bool inStr(string s, char c)
{
    int len = s.length();
    if (len == 0) return false;
    for (int i = 0; i < len; ++i)
    {
        if (c == s[i]) return true;
    }
    return false;
}

int lengthOfLongestSubstring(string s)
{
    int len = s.length();
    if (len == 0 || len == 1) return len;
    int result = 1;
    for (int i = 0; i < len; ++i)
    {
        for(int j = i+1; j < len; ++j)
        {
            string temp = s.substr(i, j-i);
            if (inStr(temp, s[j]))
            {
                result = max(result, j-i);
                break;
            }
            else result = max(result, j-i+1);
        }
    }
    return result;
}

int main()
{
    string s = "ddeeeeeeeafsagsadgsddddddvdfffffff";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
