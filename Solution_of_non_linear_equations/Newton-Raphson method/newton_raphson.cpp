#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float func(float x){
    return (x*x*x + 3*x*x - 5);
}

float der(float x){
    return (3*x*x + 6*x );
}

int main(){
    float a,b,e,f0,d0,f1;
    cout<<"Enter your initial guess: \n";
    cin>>a;
    cout<<"Enter the tolerable error: \n";
    cin>>e;
    int count=0;
    cout<<setw(5)<<"i"<<setw(10)<<"a"<<setw(15)<<"f0"<<setw(10)<<"d0"<<setw(10)<<"b"<<setw(15)<<"f1"<<setw(10)<<endl;
    do
    {
        if (der(a)<0.000005)
        {
            cout<<"Error"<<endl;
            return 0;
        }
        
        f0 = func(a);
        d0 = der(a);
        b = a - (f0/d0);
        f1 = func(b);
        a = b;
        count++;
            cout<<setprecision(6)<<fixed<<setw(5)<<count<<setw(10)<<a<<setw(15)<<f0<<setw(10)<<d0<<setw(10)<<b<<setw(15)<<abs(f1)<<setw(10)<<endl;
    } while (abs(f1)>e && count <= 20);
    
    return 0;
}