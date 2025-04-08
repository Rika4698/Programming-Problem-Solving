#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{

    ll tc;
    cin>>tc;
    while(tc--)
    {
        ll n;
        cin>>n;
        vector<ll>v(n);
        ll s=0;
        for(int i=0;i<n;i++){ cin>>v[i];
                             s+=v[i];
                            }
        ll l=0,r=2e9,ans=-1;
        while(l<=r)
        {
            ll mid=(l+(r-l)/2);
            if((mid*(mid+1))/2<=s)
            {
                ans=mid+1;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }


}
