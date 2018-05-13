#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string times(string s, char c)
    {
        int len = s.length();
        if (len == 0) return "";
        if (c == '0') return "0";
        string result = "";
        int value = 0;
        int carry = 0;
        for (int i = len-1;  i >= 0; i--)
        {
            value = (c - '0')*(s[i] - '0') + carry;
            carry = value/10;
            value = value%10;
            result = result + to_string(value);
        }
        if (carry > 0)
        {
            result = result + to_string(carry);
        }
        len = result.length();
        string reversed = result;
        for (int i = 0; i < len; ++i)
        {
            reversed[i] = result[len-i-1];
        }
        return reversed;
    }
    string add(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 <= len2)
        {
            int diff = len2 - len1;
            string result = "";
            int value = 0;
            int carry = 0;
            for (int i = len1-1; i >= 0; i--)
            {
                value = carry + (s1[i] - '0') + (s2[i+diff] - '0');
                carry = value/10;
                value = value%10;
                result = result + to_string(value);
            }
            for (int i = len2-len1-1; i >= 0; --i)
            {
                value = carry + (s2[i] - '0');
                carry = value/10;
                value = value%10;
                result = result + to_string(value);
            }
            if (carry > 0) result = result + to_string(carry);
            string reversed = result;
            int len = result.length();
            for (int i = 0; i < result.length(); ++i)
            {
                reversed[i] = result[len-i-1];
            }
            return reversed;
        }
        else
        {
            return add(s2, s1);
        }
    }
    string sum(const vector<string> &numbers)
    {
        string result = "";
        if (numbers.size() == 0) return result;
        result = numbers[0];
        for (int i = 1; i < numbers.size(); ++i)
        {
            result = add(numbers[i], result);
        }
        return result;
    }
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        if (len1 == 0) return "";
        if (len2 == 0) return "";
        if (len1 <= len2)
        {
            vector<string> myVector;
            for (int i = 0; i < len1; ++i)
            {
                string temp = times(num2, num1[len1-i-1]);
                string extra = "";
                for (int j = 0; j < i; ++j)
                {
                    extra = extra + "0";
                }
                temp = temp + extra;
                myVector.push_back(temp);
                //cout << temp << endl;
            }
            string result = sum(myVector);
            return result;
        }
        else
        {
            return multiply(num2, num1);
        }
    }
};


int main()
{
    Solution sol;
    string s1 = "99992334555219";
    string s2 = "1234567812200001112229";
    string result = sol.multiply(s1, s2);
    cout << s1 << " * " << s2 << " = ";
    cout << result << endl;
    return 0;
}