#include<bits/stdc++.h>
using namespace std;
const long long M=2e5+10,MOD=1000000007;
typedef long long ll;
#define debug(x) cout<<x<<endl

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while(t--){
       int n,k;
       cin>>n>>k;
       string s;
       cin>>s;
       ll ans=0;
       int temp=k;
       string p=s;
       ll cntA=0;
       for(int i=0;i<n;i++)cntA+=(s[i]=='A');
       vector<ll>occA;
       for(int i=n-1;i>=0&&temp>0;i--){
          cntA-=(s[i]=='A');
          if(s[i]=='?'){
            p[i]='B';
            temp--;
            occA.push_back(cntA);
          }
       }
       ll cntB=0;
       for(int i=0;i<n;i++)cntB+=(p[i]=='B');
       ll tempB=cntB;
       for(int  i=0;i<n;i++){
        tempB-=(p[i]=='B');
        if(s[i]=='A'){
            ans+=tempB;
        }
       }
       ll answer=ans;
       int pos=(int)occA.size()-1;
      // debug(ans);
       ll newA=0;
       for(int i=0;i<n&&pos>=0;i++){
          cntB-=(s[i]=='B');
          if(s[i]=='?'){
            ans-=occA[pos];
            cntB--;
            pos--;
            ans+=cntB;
            ans-=newA;
            newA++;
          }
          answer=max(answer,ans);
       }
       cout<<answer<<"\n";
    }



    return 0;

}
