#include<bits/stdc++.h>>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int m[n][n];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>m[i][j];
            }
        }
        vector<int>a(n,(1<<30)-1);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j)
                {
                    a[i]=a[i]&m[i][j];
                }
            }
        }
        bool valid = true;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j && (a[i] | a[j]) != m[i][j])
                    valid=false;
            }
        }
        if(!valid)
        {
            cout<<"NO"<<"\n";
        }
        else
        {
            cout<<"YES"<<"\n";
            for(int i=0; i<n;i++)
            {
                cout<<a[i]<<" ";
            }
        }
        cout<<"\n";
    }


    return 0;
}
