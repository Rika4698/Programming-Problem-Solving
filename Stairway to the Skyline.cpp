#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve()
{
    ll n, k;
    cin >> n>>k;
    vector<ll> v(n);

    for(auto &x:v){
        cin>>x;
    }
    vector<ll> s = v;

    sort(s.begin(), s.end());
    ll l = -1, r = -1;
    for(int i = 0; i < n; i++){
        if(s[i] != v[i] and l == -1){
            l = i;
        }
        if(s[i] != v[i])r = i;
    }
    if(l == -1){
        cout<<"YES"<<endl;
        cout<<1<<" "<<1<<endl;
        return;
    }
    else{
        ll dif = r - l + 1;
        if(dif > k){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<l+1<<" "<<r+1<<endl;
        }

    }



}
int main()
{
    int tc = 1, cs = 1;
    // cin >> tc;
    while (tc--)
    {
        // cout<<"Case "<<cs<<": ";
        solve();
    }
    return 0;
}

