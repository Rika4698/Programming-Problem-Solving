#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;

    for(int t=1; t<=T; t++)
    {
        double k;
        cin>>k;

        double ratioW = sqrt(k*k -1);
        double ratioH =sqrt(4- k*k);

        double ratio = ratioW/ratioH;

        cout<<"Case "<<t<<": "<<fixed<<setprecision(4)<<ratio<<"\n";
    }
    return 0;
}
