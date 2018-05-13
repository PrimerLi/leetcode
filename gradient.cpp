#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

double df(double x)
{
    return 3*x*x + 4*x - 6;
}

double ddf(double x)
{
    return 6*x + 4;
}

int main()
{
    double x = 5;
    int count = 0;
    int iterationMax = 200;
    double alpha = 0.02;
    while(true)
    {
        cout << "iteration number = " << count << ", x = " << x << endl;
        double temp = x;
        x = temp - df(temp)/(ddf(temp));
        if (fabs(x - temp) < 1e-16) break;
        count++;
        if (count > iterationMax) break;
    }
    cout << x << endl;
    return 0;
}
