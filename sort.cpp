#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int uniform(int len)
{
    return rand()%len;
}

void shuffle(vector<int> &A)
{
    int len = A.size();
    for (int i = 0; i < len; ++i)
    {
        int index = uniform(len);
        int temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void printVector(const vector<int> &A)
{
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}

vector<int> quicksort(const vector<int> &A)
{
    if (A.size() == 0 || A.size() == 1) return A;
    int pivot = A[0];
    vector<int> lower;
    vector<int> equal;
    vector<int> upper;
    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] < pivot) lower.push_back(A[i]);
        else if (A[i] == pivot) equal.push_back(A[i]);
        else upper.push_back(A[i]);
    }
    lower = quicksort(lower);
    upper = quicksort(upper);
    vector<int> result;
    result.insert(result.end(), lower.begin(), lower.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), upper.begin(), upper.end());
    return result;
}

int compare(int a, int b)
{
    if (a > b) return 1;
    else if (a == b) return 0;
    else return -1;
}

void sortTwoArrays(vector<int> &A, vector<int> &B)
{
    int len = A.size();
    assert(len == B.size());
    if (len == 0 || len == 1) return;
    int pivot = A[0];
    vector<int> Blower, Bequal, Bupper;
    for (int i = 0; i < len; ++i)
    {
        if (compare(B[i], pivot) == -1) Blower.push_back(B[i]);
        else if (compare(B[i], pivot) == 0) Bequal.push_back(B[i]);
        else Bupper.push_back(B[i]);
    }
    int Bp = Bequal[0];
    vector<int> Alower, Aequal, Aupper;
    for (int i = 0; i < A.size(); ++i)
    {
        if (compare(A[i], Bp) == -1) Alower.push_back(A[i]);
        else if (compare(A[i], Bp) == 0) Aequal.push_back(A[i]);
        else Aupper.push_back(A[i]);
    }
    sortTwoArrays(Alower, Blower);
    sortTwoArrays(Aupper, Bupper);
    for (int i = 0; i < Alower.size(); ++i)
    {
        A[i] = Alower[i];
    }
    for (int i = 0; i < Aequal.size(); ++i)
    {
        A[i + Alower.size()] = Aequal[i];
    }
    for (int i = 0; i < Aupper.size(); ++i)
    {
        A[i + Alower.size() + Aequal.size()] = Aupper[i];
    }
    for (int i = 0; i < Blower.size(); ++i)
    {
        B[i] = Blower[i];
    }
    for (int i = 0; i < Aequal.size(); ++i)
    {
        B[i + Blower.size()] = Bequal[i];
    }
    for (int i = 0; i < Aupper.size(); ++i)
    {
        B[i + Blower.size() + Bequal.size()] = Bupper[i];
    }
}

int main()
{
    vector<int> A;
    vector<int> B;
    int len = 40;
    for (int i = 0; i < len; ++i)
    {
        A.push_back(i);
        B.push_back(i);
    }
    shuffle(A);
    shuffle(B);
    printVector(A);
    printVector(B);
    sortTwoArrays(A, B);
    printVector(A);
    printVector(B);
    return 0;
}
