#include<bits/stdc++.h>
const int MOD=1e6+3;

#define dbg(x) cout<<__LINE__<<x<<'\n'
#define ll long long
#define dd double
#define in int
#define st string
#define pb push_back

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i,x;
        std:vector<ll>odd,even;
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>> x;
            if(x%2)odd.pb(x);
            else even.pb(x);
        }
        for(i=0;i<odd.size();i++)
        {
            even.pb(odd[i]);

        }
        ll cnt=0;
        for(i=0;i<even.size();i++)
        {
            for(int j=i+1;j<even.size();j++)
            {
                ll gcd=__gcd(even[i],2*even[j]);
                if(gcd>1)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;


}
