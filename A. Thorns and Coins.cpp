#include<bits/stdc++.h>
using namespace std;


int maxPoints(const string& p)
{
    int n = p.length();
    vector<int>dp(n, -1);
    dp[0]=0;
    for(int i=0; i<n; i++)
    {
        if(dp[i] == -1)continue;
        if(p[i] == '*') continue;

        if(i+1 && p[i+1] != '*')
        {
            dp[i+1] = max(dp[i+1], dp[i] + (p[i+1] == '@' ? 1:0));
        }

        if(i+2 && p[i+2] != '*')
        {
            dp[i+2] = max(dp[i+2], dp[i] + (p[i+2] == '@' ? 1:0));
        }
    }

    int maxCoins = 0;
    for(int i=0; i<n; i++)
    {
        if(dp[i]!= -1)
        {
            maxCoins = max(maxCoins, dp[i]);
        }
    }
        return maxCoins;

}

int main()
{
    int t;
    cin>> t;

    while(t--)
    {
        int n;
        string p;
        cin>>n>>p;

        cout<<maxPoints(p)<<endl;
    }
    return 0;
}







/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int collectMaxCoins(const string& path) {
    int n = path.length();
    vector<int> dp(n, -1); // Initialize dp array with -1 (unreachable state)
    dp[0] = 0; // Start from the first cell, which is empty

    for (int i = 0; i < n; i++) {
        if (dp[i] == -1) continue; // If cell is unreachable, skip it
        if (path[i] == '*') continue; // Skip cells with thorns

        // Move to the next cell if possible
        if (i + 1 < n && path[i + 1] != '*') {
            dp[i + 1] = max(dp[i + 1], dp[i] + (path[i + 1] == '@' ? 1 : 0));
        }

        // Move two cells ahead if possible
        if (i + 2 < n && path[i + 2] != '*') {
            dp[i + 2] = max(dp[i + 2], dp[i] + (path[i + 2] == '@' ? 1 : 0));
        }
    }

    // Find the maximum coins collected at any reachable cell
    int maxCoins = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] != -1) {
            maxCoins = max(maxCoins, dp[i]);
        }
    }
    return maxCoins;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string path;
        cin >> n >> path;

        // Compute and output the result for each test case
        cout << collectMaxCoins(path) << endl;
    }

    return 0;
}*/


/*#include <bits/stdc++.h>
#define ll long long int
#define nline '\n'
using namespace std;

void solve()
{
    ll n;
    cin >> n;

    string s;
    cin >> s;

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '.' and s[i + 1] == '*' and s[i + 2] == '*')
            break;
        if (s[i] == '@')
        {
            ans++;
            if (s[i + 1] == '*' and s[i + 2] == '*')
                break;
        }
    }

    cout << ans << nline;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }

} */
