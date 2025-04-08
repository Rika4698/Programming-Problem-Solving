#include<iostream>
using namespace std;
int main()
{
    int n,m,equ1,equ2,pair=0,sum;
    cin>> n >> m;
    sum=n+m;
    for(int a=0;a<sum;a++)
    {
        for(int b=0;b<sum;b++)
        {
            equ1=(a*a)+b;
            equ2=a+(b*b);
            if(equ1==n&&equ2==m)
            {
                pair++;
            }
        }

    }
    cout<<pair<<endl;
    return 0;
}
