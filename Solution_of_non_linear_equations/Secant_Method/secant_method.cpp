
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float func(float x)
{
    return (x * x * x + 3 * x * x - 5);
}

int main()
{
    float a, b, c, e, f0, f1, f2;
    cout << "Enter your starting interval: \n";
    cin >> a;
    cout << "Enter your closing interval: \n";
    cin >> b;
    cout << "Enter the tolerable error: \n";
    cin >> e;
    int count = 0;
    cout << setw(5) << "i" << setw(20) << "a" << setw(20) << "b" << setw(20) << "f0" << setw(20) << "f1" << setw(20) << "c" << setw(20) << "f2" << setw(20) << endl;
    do
    {
        count++;
        f0 = func(a);
        f1 = func(b);
        if (abs(f1-f0)<0.000005)
        {
            cout<<"Error"<<endl;
            return 0;
        }
        c = (((a * f1) - (b * f0)) / (f1 - f0));
        f2 = func(c);
        f0 = f1;
        f1 = f2;
        cout << setprecision(5) << fixed << setw(5) << count << setw(20) << a << setw(20) << b << setw(20) << f0 << setw(20) << f1 << setw(20) << c << setw(20) << f2 << setw(20) << endl;
        a = b;
        b = c;
    } 
    while (abs(f2) > e && count <= 20);
    return 0;
}
