#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

struct data
{
    int count;
    char c;
    data(int count, char c)
    {
        this->count = count;
        this->c = c;
    }
};

int find(const vector<data> &myVector, char c)
{
    if (myVector.size() == 0) return -1;
    for (int i = 0; i < myVector.size(); ++i)
    {
        if (c == myVector[i].c) return i;
    }
    return -1;
}

vector<data> stringCount(string s)
{
    int len = s.length();
    vector<data> result;
    for (int i = 0; i < len; ++i)
    {
        int index = find(result, s[i]);
        if (index < 0)
        {
            result.push_back(data(1, s[i]));
        }
        else
        {
            result[index].count = result[index].count + 1;
        }
    }
    return result;
}

void print(const vector<data> &myVector)
{
    for (int i = 0; i < myVector.size(); ++i)
    {
        cout << myVector[i].c << ": " << myVector[i].count << endl;
    }
}

unordered_map<char, int> string_stat(string s)
{
    unordered_map<char, int> result;
    for (int i = 0; i < s.length(); ++i)
    {
        if (result.find(s[i]) != result.end()) result[s[i]] = result[s[i]] + 1;
        else result[s[i]] = 1;
    }
    return result;
}

int main()
{
    string s = "idsaongosdddddddainsanbgza;loingasoiboi;;;::::h098ihva8hwe::a08ugv";
    vector<data> stat = stringCount(s);
    print(stat);
    cout << endl;
    
    unordered_map<char, int> result = string_stat(s);
    for (auto ele : result)
    {
        cout << ele.first << ": " << ele.second << endl;
    }
    return 0;
}
