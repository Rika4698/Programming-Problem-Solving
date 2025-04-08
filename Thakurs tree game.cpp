#include<bits/stdc++.h>
using namespace std;
const long long M=2e5+10,MOD=998244353;
typedef long long ll;
#define debug(x) cout<<x<<endl
int level[M];
int dp[M][2];
int low[M];
int up[M];
int mx=0;
int n,k;
int bonus[M];
vector<int>edge[M];
void dfs1(int x,int p){
    for(auto it:edge[x]){
        if(it!=p){
            up[it]=up[x]+1;
            if(x==1){
                low[it]=dp[x][0];
                if(dp[x][0]==level[it]+1)low[it]=dp[x][1];
                low[it]--;
                low[it]=max(low[it],0);
            }
            else{
                low[it]=low[x];
                int cur=dp[x][0];
                if(dp[x][0]==level[it]+1)cur=dp[x][1];
                cur-=1;
                cur=max(0,cur);
                bonus[it]=bonus[x];
                bonus[it]+=cur;
                mx=max(mx,up[it]+min(low[x]+bonus[it],k));
            }
            dfs1(it,x);
        }
    }
}
void dfs(int x,int p){
    for(auto it:edge[x]){
        if(it!=p){
            dfs(it,x);
        }
    }
    level[p]=max(level[p],level[x]+1);
    if(dp[p][0]<level[p]){
        swap(dp[p][0],dp[p][1]);
        dp[p][0]=level[p];
    }
    else if(level[x]+1>dp[p][1])dp[p][1]=level[x]+1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
   // cin>>t;
    while(t--){
       //int n,k;
       cin>>n>>k;
       for(int i=1;i<=n;i++)level[i]=1;
       for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
       }
       dp[1][0]=1;
       dfs(1,0);
       mx=dp[1][0];
       up[1]=1;
       mx+=min(max(0,dp[1][1]-1),k);
       dfs1(1,0);
       cout<<min(mx,n)<<"\n";

    }



    return 0;

}
