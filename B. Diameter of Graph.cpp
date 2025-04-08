#include<bits/stdc++.h>
using  namespace  std;
typedef long long int ll;
typedef unsigned long long int  llu;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,k;
        cin>>n>>m>>k;
        if(m<(n-1))cout<<"NO"<<endl;
        else if(m>(n*(n-1))/2)cout<<"NO"<<endl;
        else if(k<=1)cout<<"NO"<<endl;
        else if(k==2)
        {
            if(n==1)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else if(k==3)
        {
            if(m==(n*(n-1))/2)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
    }
    return 0;
}
