#include<bits/stdc++.h>
using namespace std;
int main()
{
    string a1,a2;
    cin>>a1>>a2;
    for(int i=0;i<a2.size();i++)
    {
        if(a1[i]!=a2[i])
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    return 0;
}
