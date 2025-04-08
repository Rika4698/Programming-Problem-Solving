#include<bits/stdc++.h>

using namespace std;

double calculate(double d)
{
    double a = sqrt(d/2.0); // side of the base
    double h = a/2.0;  // height of the pyramid
    double volume = (1.0/3.0)* a * a * h; // Volume of the pyramid
    return volume;
}
int main()
{
    int T;
    cin>>T;

    for(int i=1; i<=T; i++)
    {
        double d;
        cin>>d;
        double pyramid = calculate(d);
        cout<<"Case "<<i<<": "<<fixed<<setprecision(4)<<pyramid<<"\n";

    }
    return 0;
}
