#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int count=0;
    string f=" ",s=" ";
    while(n--)
    {
        cin>>s;
        if(f!=s)
        {
            count++;
            f=s;

        }
    }
    cout<<count<<endl;
}
