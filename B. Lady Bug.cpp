#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;

    int count1=0, count2=0, sum1=0,sum2=0;

    for(int i=0;i<n;i++)
    {
        if(i%2 == 0)
        {
            if(s[i]=='0')
            {
                count1++;

            }
            sum1++;
        }else{
        if(t[i]=='0')
            count1++;
        }
    }

    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            if(t[i] == '0')
                count2++;
        }
        else{
            if(s[i]=='0')
            {
                count2++;

            }
            sum2++;
        }


    }

    if(count1 >= sum1 && count2 >= sum2)
    {
        cout<<"YES"<<endl;
    }
    else{
         cout<<"NO"<<endl;
    }


}

int main()
{
    int t ;
    cin>> t;
    while(t--)
    {
        solve();

    }
    return 0;
}
