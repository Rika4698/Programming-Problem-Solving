#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    string b="hello";
    int x=0,y=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==b[x])
        {
            x++;
            y++;
        }
    }
    if(y==5)
    {
        cout<<"YES";
    }
    else{cout<<"NO";}
    return 0;
}
