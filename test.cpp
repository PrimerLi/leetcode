#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

void print(const vector<int> &a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << ", ";
    cout << endl;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    print(a);
    a.erase(a.end() - 1);
    print(a);
    return 0;
}
