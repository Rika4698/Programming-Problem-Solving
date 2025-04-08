#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        vector<int>arr(n);
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        vector<int>lsum(n+1,0);
        long long result = 0;
        for(int i=0; i<n; i++)
        {
            vector<int>rsum(n+1,0);
            for(int j=n-1; j>i; j--)
            {
                result= result+(lsum[arr[j]] * rsum[arr[i]]);
                rsum[arr[j]]++;
            }
            lsum[arr[i]]++;
        }
        cout<<result<<"\n";
    }
    return 0;
}
