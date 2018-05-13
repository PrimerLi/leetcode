#include <iostream>
#include <vector>
using namespace std;

int fib(int n)
{
    if (n == 0 || n == 1) return 1;
    //return fib(n-1) + fib(n-2);
    vector<int> result(n+1, 0);
    result[0] = result[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        result[i] = result[i-1] + result[i-2];
    }
    return result[n];
}

int main()
{
    int len = 40;
    for (int i = 0; i < len; ++i)
    {
        cout << fib(i) << endl;
    }
    return 0;
}
