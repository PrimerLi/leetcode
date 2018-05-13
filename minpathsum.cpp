#include <iostream>
#include <vector>
#include <cassert>
using  namespace std;

int minPathSum(vector<vector<int> > &matrix)
{
    int row = matrix.size();
    assert(row > 0);
    int col = matrix[0].size();
    assert(col > 0);
    for (int i = row-1; i >= 0; --i)
    {
        for (int j = col-1; j >= 0; --j)
        {
            if (i == row-1 && j == col-1) continue;
            else if (i == row-1)
                matrix[i][j] = matrix[i][j] + matrix[i][j+1];
            else if (j == col-1)
                matrix[i][j] = matrix[i][j] + matrix[i+1][j];
            else 
                matrix[i][j] = min(matrix[i+1][j], matrix[i][j+1]) + matrix[i][j];
        }
    }
    return matrix[0][0];
}

void printMatrix(const vector<vector<int> > &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int row = 5;
    int col = 6;
    int mod  = row*col;
    vector<vector<int> > matrix;
    for (int i = 0; i < row; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < col; ++j)
        {
            temp.push_back(rand()%mod);
        }
        matrix.push_back(temp);
    }
    printMatrix(matrix);
    cout << minPathSum(matrix) << endl;
    printMatrix(matrix);
    return 0;
}
