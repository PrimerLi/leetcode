#include <iostream>
#include <string>
using namespace std;

bool interleaving(string s1, string s2, string s3)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if (len1 + len2 != len3)
    {
        cout << len1 << "  " << len2 << "  " << len3 << endl;
        return false;
    }
    if (len1 == 0) return s2==s3;
    if (len2 == 0) return s1 == s3;
    if (s3[len3-1] == s1[len1-1])
    {
        return interleaving(s1.substr(0, len1-1), s2, s3.substr(0, len3-1));
    }
    else if (s3[len3-1] == s2[len2-1])
    {
        return interleaving(s1, s2.substr(0, len2-1), s3.substr(0, len3-1));
    }
    else return false;
}

bool dp(string s1, string s2, string s3)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = s3.length();
    if (len1 + len2 != len3) return false;
    bool table[len1+1][len2+1];
    table[0][0] = true;
    for (int i = 1; i <= len1; ++i)
    {
        table[i][0] = table[i-1][0] && (s3[i-1] == s1[i-1]);
    }
    for (int i = 1; i <= len2; ++i)
    {
        table[0][i] = table[0][i-1]&&(s3[i-1] == s2[i-1]);
    }
    for (int i = 1; i <= len1; ++i)
    {
        for (int j = 1; j <= len2; ++j)
        {
            table[i][j] = ((s3[i+j-1] == s1[i-1])&&table[i-1][j])||((s3[i+j-1] == s2[j-1])&&table[i][j-1]);
        }
    }
    return table[len1][len2];
}

int main()
{
    string s1 = "printThisistring";
    string s2 = "nokd";
    string s3 = s1+s2;
    cout << dp(s1, s2, s3) << endl;
    cout << interleaving(s1, s2, s3) << endl;
    return 0;
}
