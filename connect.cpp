#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <stack>
#include <unordered_map>
using namespace std;

void printVector(const vector<int> &numbers);

int find(const vector<int> &a, int target)
{
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] == target) return i;
    }
    return -1;
}

vector<int> combine(const vector<int> &a, const vector<int> &b)
{
    vector<int> result(a);
    for (int i = 0 ; i < b.size(); ++i)
    {
        if (find(a, b[i]) < 0) result.push_back(b[i]);
    }
    return result;
}

vector<int> getLongestPath(vector<pair<int, int> > &pairs)
{
    vector<int> result;
    int size = pairs.size();
    if (size == 0) return result;
    unordered_map<int, vector<int> > map;
    for (int i = 0; i < size; ++i)
    {
        int first = pairs[i].first;
        int second = pairs[i].second;
        vector<int> temp;
        if (first != second)
        {
            temp.push_back(first);
            temp.push_back(second);
        }
        else
            temp.push_back(first);
        map[first] = combine(map[first], temp);
        map[second] = combine(map[second], temp);
        map[first] = map[second] = combine(map[first], map[second]);
    }

    for (int i = 0; i < size; ++i)
    {
        int first = pairs[i].first;
        int second = pairs[i].second;
        vector<int> temp = combine(map[first], map[second]);
        map[first] = map[second] = temp;
        //cout << first << " : ";
        //printVector(temp);
    }
    
    int maxValue = 0;
    for (auto ele : map)
    {
        cout << ele.first << ": ";
        printVector(ele.second);
        if (maxValue < ele.second.size()) maxValue = ele.second.size();
    }
    for (auto ele : map)
    {
        if (maxValue == ele.second.size()) {
            result = ele.second;
            break;
        }
    }
    return result;
}

void printVector(const vector<int> &numbers)
{
    for (int i = 0; i < numbers.size(); ++i)
        cout << numbers[i] << ", ";
    cout << endl;
}

int main()
{
    vector<pair<int, int> > pairs;
    int len = 11;
    ofstream ofile("pair.txt");
    ofile << len << endl;
    for (int i = 0; i < len; ++i)
    {
        int a, b;
        a = rand()%(len) + 1;
        b = rand()%(len) + 1;
        ofile << a << "    " << b << endl;
        pair<int, int> p(a, b);
        pairs.push_back(p);
    }
    ofile.close();
    /*ifstream ifile("pair.txt");
    ifile >> len;
    for (int i = 0; i < len; ++i)
    {
        int a, b;
        ifile >> a >> b;
        pair<int, int> p(a, b);
        pairs.push_back(p);
    }
    ifile.close();*/
    
    vector<int> path = getLongestPath(pairs);
    printVector(path);
    return 0;
}
