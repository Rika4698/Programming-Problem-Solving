#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    string a;
    map<string,int>reg;
    for(int i=0;i<t;i++)
    {
        cin>>a;
        if(reg[a]==0)
        {
            reg[a]=1;
            cout<<"OK"<<endl;
        }
        else
        {
            cout<<a<<reg[a]<<endl;
            reg[a]++;
        }
    }
    return 0;
}
