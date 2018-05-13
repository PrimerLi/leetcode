#include <iostream>
#include <cstring>
using namespace std;

string lcs(string s1, string s2)
{
    string result = "";
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 == 0 || len2 == 0) return result;
    if (len1 == 1)
    {
        for (int i = 0; i < len2; ++i)
        {
            if (s1[0] == s2[i]) return s1;
        }
        return "";
    }
    if (len2 == 1)
    {
        for (int i = 0; i < len1; ++i)
        {
            if (s2[0] == s1[i]) return s2;
        }
        return "";
    }
    if (s1[len1-1] == s2[len2-1])
    {
        string head1 = s1.substr(0, len1-1);
        string head2 = s2.substr(0, len2-1);
        string previous = lcs(head1, head2);
        result = previous + s1.substr(len1-1);
        return result;
    }
    else
    {
        string head1 = s1.substr(0, len1-1);
        string head2 = s2.substr(0, len2-1);
        string result1 = lcs(head1, s2);
        string result2 = lcs(s1, head2);
        if (result1.length() > result2.length()) return result1;
        else return result2;
    }
}

int main()
{
    string s1 = "a1bc2d";
    string s2 = "afdadfadsbgewhbbewag___cadfad";
    cout << lcs(s1, s2) << endl;
    return 0;
}
