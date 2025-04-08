#include<iostream>
#include<string>
using namespace std;
int main()
{
    int up=0,low=0;
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(isupper(a[i]))
        {
            up++;
        }
        else{low++;}
    }
    if((up<low)||(up==low))
    {
        for(int i=0;i<a.size();i++)
        {
            a[i]=tolower(a[i]);
        }
        cout<<a<<endl;
    }
    else if(up>low)
    {
        for(int i=0;i<a.size();i++)
        {
            a[i]=toupper(a[i]);
        }
        cout<<a<<endl;
    }
    return 0;
}
