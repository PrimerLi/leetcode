#include <iostream>
using namespace std;

class Solution1 {
public:
    int uniquePaths(int m, int n)
    {
        int table[m+1][n+1];
        for(int i = 1; i < m+1; ++i)
        {
            table[i][1] = 1;
        }
        for (int i = 1; i < n+1; ++i)
        {
            table[1][i] = 1;
        }
        for (int i = 2; i <= m; ++i)
        {
            for (int j = 2; j <= n; ++j)
            {
                table [i][j] = table[i][j-1] + table[i-1][j];
            }
        }
        return table[m][n];
    }
};

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        int table[m+1][n+1];
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 0; j <= n; ++j)
                table[i][j] = 1;
        }
        for (int i = 2; i <= m; ++i)
        {
            for (int j = 2; j <= n; ++j)
            {
                table [i][j] = table[i][j-1] + table[i-1][j];
            }
        }
        return table[m][n];
    }
};

int main(int argc, char **argv)
{
    int m, n;
    m = atoi(argv[1]);
    n = atoi(argv[2]);
    Solution1 s1;
    cout << s1.uniquePaths(m,n) << endl;
    Solution s;
    cout << s.uniquePaths(m,n) << endl;
    return 0;
}
