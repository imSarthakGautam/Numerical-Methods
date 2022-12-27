#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

float func(float x){
    return (x*x*x + 3*x*x - 5);
}

int main(){
    float a,b,e;
    float f0,f1,mid,fmid;
    cout<<"Enter the initial interval: "<<endl;
    cin>>a;
    cout<<"Enter the final interval: "<<endl;
    cin>>b;
    cout<<"What is the tolerable error? : "<<endl;
    cin>>e;
    cout<<endl;
    int n = ceil((log10(b-a)-log10(e))/log10(2));
    cout<<"The minimum number of iterations required are : "<<n<<endl<<endl;
    int count=0;
    cout<<setw(5)<<"i"<<setw(10)<<"a"<<setw(10)<<"b"<<setw(10)<<"mid"<<setw(10)<<"fmid"<<setw(10)<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;
    do{
        f0 = func(a);
        f1 = func(b);
        mid = (a+b)/2;
        fmid = func(mid);
        if (f0*fmid > 0)
        {
            a = mid;
        }
        else{
            b = mid;
        }
        count++;
        cout<<setw(5)<<count<<setw(10)<<a<<setw(10)<<b<<setw(10)<<mid<<setw(15)<<fmid<<setw(10)<<endl;
        
    }while((abs(fmid) > e && count <= (2*n)));
    return 0;
}