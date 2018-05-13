#include <iostream>
#include <vector>
using namespace std;

int minSum(vector<vector<int> > &triangle)
{
    int row = triangle.size();
    if (row == 0) return 0;
    if (row == 1) return triangle[0][0];
    vector<vector<int> > leftTriangle;
    vector<vector<int> > rightTriangle;
    for (int i = 1; i < row; ++i)
    {
        vector<int> head(triangle[i].begin(), triangle[i].end()-1);
        leftTriangle.push_back(head);
        vector<int> tail(triangle[i].begin()+1, triangle[i].end());
        rightTriangle.push_back(tail);
    }
    return triangle[0][0] + min(minSum(leftTriangle), minSum(rightTriangle));
}

int dp(vector<vector<int> > triangle)
{
    int row = triangle.size();
    if (row == 0) return 0;
    if (row == 1) return triangle[0][0];
    for (int i = row-2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); ++j)
        {
            triangle[i][j] = min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        }
    }
    return triangle[0][0];
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << "  ";
    }
    cout << endl;
}
int main()
{
    vector<vector<int> > triangle;
    int row = 6;
    int mod = row*row;
    for (int i = 0; i < row; ++i)
    {
        vector<int> temp(i+1, 0);
        for (int j = 0; j < temp.size(); ++j)
        {
            temp[j] = rand()%mod + 1;
        }
        triangle.push_back(temp);
    }

    for (int i = 0; i < row; ++i)
    {
        printVector(triangle[i]);
    }
    cout << minSum(triangle) << endl;
    cout << dp(triangle) << endl;
    return 0;
}
