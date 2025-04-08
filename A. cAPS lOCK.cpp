#include<iostream>
#include<string>
using namespace std;
int main()
{
    string n;
    cin>>n;
    int c=0,d=0;
    for(int i=1;i<n.size();i++)
    {
        if(islower(n[i]))
        {
            c++;
        }
    }
    for(int i=0;i<n.size();i++)
    {
        if(isupper(n[i]))
        {
            d++;
        }
    }
    if(islower(n[0])&&c==0)
    {
        n[0]=toupper(n[0]);
        for(int i=1;i<n.size();i++)
        {
            n[i]=tolower(n[i]);
        }
        cout<<n;
        return 0;
    }
    if (d==n.size())
    {
        for(int i=0;i<n.size();i++)
        {
            n[i]=tolower(n[i]);

        }
        cout<<n;
    }
    else{cout<<n;}
    return 0;
}
