#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0 || len == 1) return 0;
        int initial = 0;
        while(s[initial] == ')')
        {
            initial++;
        }
        string new_string = s.substr(initial, len-initial);
        //cout << new_string << endl;
        stack<char> myStack;
        int count = 0;
        myStack.push(new_string[0]);
        for (int i = 1; i < new_string.length(); ++i)
        {
            if (new_string[i] == ')')
            {
                if (myStack.empty())
                {
                    continue;
                }
                char c = myStack.top();
                if (c == '(')
                {
                    myStack.pop();
                    count = count + 2;
                }
                else
                    myStack.push(new_string[i]);
            }
            else
            {
                myStack.push(new_string[i]);
            }
        }
        return count;
    }
};

int main()
{
    string s = ")))))))()()()()(((()))))))))";
    Solution mySolution;
    cout << mySolution.longestValidParentheses(s) << endl;
    return 0;
}
