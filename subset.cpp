#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > subsets(const vector<int> &myVector, int m)
{
    vector<vector<int> > result;
    if (myVector.size() == 0) return result;
    if (m == 0) return result;
    if (m == 1)
    {
        for (int i = 0; i < myVector.size(); ++i)
        {
            vector<int> temp;
            temp.push_back(myVector[i]);
            result.push_back(temp);
        }
        return result;
    }
    if (m > myVector.size()) return result;
    vector<int> tail(myVector.begin() + 1, myVector.end());
    vector<vector<int> > withoutHead = subsets(tail, m);
    vector<vector<int> > withHead = subsets(tail, m-1);
    for (int i = 0; i < withoutHead.size(); ++i)
    {
        result.push_back(withoutHead[i]);
    }
    for (int i = 0; i < withHead.size(); ++i)
    {
        withHead[i].insert(withHead[i].begin(), myVector[0]);
        result.push_back(withHead[i]);
    }
    return result;
}

vector<vector<int> > subsets(const vector<int> &myVector)
{
    vector<vector<int> > result;
    vector<int> nullVector;
    result.push_back(nullVector);
    for (int i = 1; i <= myVector.size(); ++i)
    {
        vector<vector<int> > tempResult = subsets(myVector, i);
        for (int j = 0; j < tempResult.size(); ++j)
        {
            result.push_back(tempResult[j]);
        }
    }
    return result;
}

void printVector(const vector<int> &myVector)
{
    if (myVector.size() == 0)
    {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (int i = 0; i < myVector.size()-1; ++i)
        cout << myVector[i] << ", ";
    cout << myVector[myVector.size()-1];
    cout << "]";
    cout << endl;
}

int main()
{
    int length = 6;
    vector<int> array;
    for (int i = 0; i < length; ++i)
    {
        array.push_back(i+1);
    }
    vector<vector<int> > result = subsets(array);
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i)
    {
        printVector(result[i]);
    }
}
