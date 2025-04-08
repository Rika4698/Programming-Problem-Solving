#include<iostream>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    if(n%2 != 0)
    {
        cout<< "-1" <<endl;
    }

    else
    {
        for(i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                cout<<i-1<<endl;
            }
            else{cout<<i+1<<endl;}
        }
    }
    return 0;
}

