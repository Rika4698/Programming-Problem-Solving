#include <bits/stdc++.h>
using namespace std;

void hobby()
{
    int t;
    cin>> t;
    while(t--)
    {
        int n;
        cin>> n;
        vector<int>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i];
            p[i]--;
        }
        string s;
        cin>>s;

        vector<int> visited(n,0);
        vector<int> result(n,0);

        for(int i=0;i<n;i++)
        {
            if(visited[i])continue;
            vector<int>cycle;
            int  current = i;
            while(!visited[current])
            {
                visited[current] = 1;
                cycle.push_back(current);
                current=p[current];

            }
            int black_count = 0;
            for(int x : cycle)
            {
                if(s[x] == '0')
                {
                    black_count++;
                }
            }

            for(int x : cycle)
            {
                result[x] = black_count;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<< result[i] <<" ";

        }
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    hobby();
    return 0;
}
