#include<bits/stdc++.h>

using namespace std;

int practice(int n)
{
    if(n==0)return 0;
    return(n%9 == 0)? 9:(n%9);
}
int main()
{

    int n;
    while(cin>>n&&n!=0)
    {
        cout<< practice(n)<<"\n";

    }

    return 0;
}

