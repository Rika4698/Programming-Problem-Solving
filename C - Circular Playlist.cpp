#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>>N;
    long long T;
    cin>>T;

    vector<long long>A(N);

    long long totalDuration = 0;

    for(int i = 0 ; i<N; i++)
    {
        cin>>A[i];
        totalDuration = totalDuration + A[i];
    }

    T = T%totalDuration;

    for(int i=0; i<N; i++)
    {
        if(T<A[i])
        {
            cout<<(i+1)<<" "<<T<<"\n";
            return 0;
        }
        T = T - A[i];
    }

    return 0;
}
