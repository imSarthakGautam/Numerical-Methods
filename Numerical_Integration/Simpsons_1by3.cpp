#include <iostream>
#include <math.h>

using namespace std;

float f(float x)
{
    return (1 / (1 + (x * x)));
}

int main()
{
    float a, b, sum, h, k;
    int i, n;

    cout << "Input: " << endl;
    cout << "Enter initial interval: ";
    cin >> a;
    cout << endl;
    cout << "Enter final interval: ";
    cin >> b;
    cout << endl;
    cout << "Enter number of sub-intervals: ";
    cin >> n;

    //calculate h
    h = (b - a) / n;

    sum = f(a) + f(b);

    for (i = 1; i <= n - 1; i++)
    {
        k = a + i * h;

        if (i % 2 == 0)
        {
            sum = sum + 2 * (f(k));
        }
        else
        {
            sum = sum + 4 * (f(k));
        }
    }

    sum = sum * h / 3;

    cout << "The integral is: " << sum << endl;

    return 0;
}
