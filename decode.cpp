#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool isValid(char c)
{
    return c != '0';
}

bool isValid(char a, char b)
{
    if (a == '0') return false;
    else 
    {
        int number = 10*(a - '0') + b - '0';
        return number <= 26;
    }
}

int decode(string s)
{
    int len = s.length();
    int table[len+1];
    table[0] = 1;
    table[1] = (s[0]=='0')? 0 : 1;
    for (int i = 2; i <= len; ++i)
    {
        if (isValid(s[i-1]) && isValid(s[i-2], s[i-1])) table[i] = table[i-1] + table[i-2];
        else if (isValid(s[i-1]) && !isValid(s[i-2], s[i-1])) table[i] = table[i-1];
        else if (!isValid(s[i-1]) && isValid(s[i-2], s[i-1])) table[i] = table[i-2];
        else table[i] = 0;
    }
    return table[len];
}

int main()
{
    string s = "99999999999";
    cout << decode(s) << endl;
    return 0;
}
