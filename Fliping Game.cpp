
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll tc; cin>>tc;
    while(tc--){
      ll n; cin>>n;
      string s; cin>>s;

      ll mx = 0, cnt=0;
      for(char ch : s){
        if(ch == '0'){
          cnt++;
          mx = max(mx, cnt);
        }
        else cnt=0;
      }
      cout << mx << endl;
    }

    return 0;
}
