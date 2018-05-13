#include <iostream>
#include <vector>
using namespace std;

vector<int> splitNumber(int num)
{
    vector<int> result;
    while(num > 0)
    {
        int r = num%10;
        result.push_back(r);
        num = num/10;
    }
    return result;
}

int main()
{
    int num = 1234455577;
    cout << num << endl;
    vector<int> result = splitNumber(num);
    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i] << ", ";
    }
    cout << endl;
    return 0;
}
