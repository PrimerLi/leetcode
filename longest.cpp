#include <iostream>
#include <vector>
#include <cassert>
#include <utility>
using namespace std;

int longest(string s)
{
    int len = s.length();
    int table[len][len];
    for (int i = len-1; i >= 0; i--)
    {
        table[i][i] = 1;
        for (int j = i+1; j < len; ++j)
        {
            if (s[i] == s[j]) table[i][j] = table[i+1][j-1] + 2;
            else table[i][j] = max(table[i+1][j], table[i][j-1]);
        }
    }
    return table[0][len-1];
}

pair<int,int> getMax(pair<int,int> p1, pair<int,int> p2)
{
    assert(p1.first <= p1.second);
    assert(p2.first <= p2.second);
    if ((p1.second - p1.first) > (p2.second - p2.first)) return p1;
    else return p2;
}
string longestPalindrome(string s)
{
    int len = s.length();
    if (len == 0 || len == 1) return s;
    if (len == 2)
    {
        if (s[0] == s[1]) return s;
        else return to_string(s[0]);
    }
    bool table[len][len];
    pair<int, int> p(0, 0);
    for (int i = len-1; i >= 0; i--)
    {
        table[i][i] = true;
        for (int j = i+1; j < len; ++j)
        {
            if (j-i > 1) table[i][j] = table[i+1][j-1]&&(s[i] == s[j]);
            else table[i][j] = (s[i] == s[j]);
            //cout << i << ", " << j << ", " << table[i][j] << endl;
            if (table[i][j]) p = getMax(p, pair<int, int>(i ,j));
        }
    }
    return s.substr(p.first, p.second - p.first + 1);
}

int main()
{
    string s = "abbdddgddaaaadjagndsakln";
    cout << longestPalindrome(s) << endl;
    return 0;
}
