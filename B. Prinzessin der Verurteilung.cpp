#include<bits/stdc++.h>
const int MOD=1e6+3;

#define dbg(x) cout<<__LINE__<<x<<'\n'
#define ll long long
#define dd double
#define in int

using namespace std;

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
     ll n,i,sz,j;
     string s,x,y,z;
     cin>>n>>s;
     set<string>st;
     set<string>:: iterator it;

     for(i=0;i<n;i++)
     {
        x="";
        for(j=i;j<n;j++)
        {
            x+=s[j];
            st.insert(x);
        }
     }
    vector<string>v;

    for(i=0;i<26;i++)
    {
        y=i+'a';
        v.push_back(y);
    }
    string ss,ans;
    for(i=0;i<26;i++)
    {
        z=i+'a';
        for(j=0;j<26;j++)
        {
            ss=z;
            ss+=j+'a';
            v.push_back(ss);
        }
    }
    string x1,y1,z1;

    for(i=0;i<26;i++)
    {
        x1=i+'a';
        for(j=0;j<26;j++)
        {
            y1=x1;
            y1+=(j+'a');
            for(int k=0;k<26;k++)
            {
                z1=y1;
                z1+=(k+'a');
                v.push_back(z1);
            }
        }
    }
    //for(i=0;i<v.size();i++)
        //cout<<v[i]<<" ";

    for(i=0;i<v.size();i++)
        {
            if(st.find(v[i])==st.end())
            {
                ans=v[i];
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
