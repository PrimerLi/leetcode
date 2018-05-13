#include <iostream>
#include <string>
using namespace std;

string lcs(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int table[len1+1][len2+1];
    string result;
    int len;
    int index;

    len = 0;
    index = 0;
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if (i == 0 || j == 0) table[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else
            {
                table[i][j] = 0;
            }
            if (len < table[i][j])
            {
                len = table[i][j];
                index = i-1;
            }
        }
    }

    return s1.substr(index-len+1, len);
}

int subsequence(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int result = 0;
    int table[len1+1][len2+1];
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
        {
            if (i == 0 || j == 0) table[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
            {
                table[i][j] = table[i-1][j-1] + 1;
            }
            else
            {
                table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
            result = max(result, table[i][j]);
        }
    }
    return result;
}
int main()
{
    string s1 = "abcdefaafdsajgodsinaasdoigna targetstringzzzaaaa asoingdsakongdsaklj:jfsdaoihgdsa";
    string s2 = "bcdsabc targetstringzzzaaaa nt hihgaasfdongdsakjfsdaiuwoiv";
    cout << lcs(s1, s2) << endl;
    cout << subsequence(s1, s2) << endl;
    return 0;
}
