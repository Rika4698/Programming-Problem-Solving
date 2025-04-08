#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    for(int n=1; n<=t; n++)
    {

        char a, b;
        cin>> a>> b;
        cout<<"Case "<<n<<":"<<"\n";
        int dif=abs(a-b);
        /*cout<< dif<<'\n';*/
        for(int i=1; i<=dif; i++)
        {
            int m;
            if(dif%i == 0)
            {
                if(94%i == 0)
                {
                    m=(94/i);
                }
                else
                {
                    m=(94/i)+1;

                }

                cout <<i<<" "<<m<<"\n";
            }
        }
        cout <<'\n';
    }
    return 0;
}
