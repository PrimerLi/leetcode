#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void printMatrix(const vector<vector<int> > &matrix);

int det(const vector<vector<int> > &matrix)
{
    int row = matrix.size();
    assert(row > 0);
    int col = matrix[0].size();
    assert(row == col);
    int dimension = row;
    if (dimension == 1) return matrix[0][0];
    if (dimension == 2)
    {
        return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
    }
    int result = 0;
    for (int i = 0; i < dimension; ++i)
    {
        vector<vector<int> > submatrix;
        for (int row = 1; row < dimension; row++)
        {
            vector<int> temp;
            for (int col = 0; col <= i-1; ++col)
            {
                temp.push_back(matrix[row][col]);
            }
            for (int col = i+1; col < dimension; ++col)
            {
                temp.push_back(matrix[row][col]);
            }
            submatrix.push_back(temp);
        }
        //printMatrix(submatrix);
        result = result + matrix[0][i]*det(submatrix)*(i%2==0? 1: -1);
    }
    return result;
}

void printMatrix(const vector<vector<int> > &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; ++i)
    {
        cout << "{";
        for (int j = 0; j < col; ++j)
        {
            if (j < col-1) cout << matrix[i][j] << ", ";
            else cout << matrix[i][j];
        }
        cout << "}, ";
    }
}

int main()
{
    vector<vector<int> > matrix;
    int dimension = 10;
    for (int i = 0; i < dimension; ++i)
    {
        vector<int> temp;
        for (int j = 0; j < dimension; ++j)
        {
            temp.push_back(rand()%dimension);
        }
        matrix.push_back(temp);
    }
    printMatrix(matrix);
    cout << det(matrix) << endl;
    return 0;
}
