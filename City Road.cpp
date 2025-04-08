#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 200005;

vector<int> adj[MAXN];
long long ways[MAXN], subtree_size[MAXN];
int n;

void dfs1(int node, int parent) {
    subtree_size[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs1(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
            ways[1] = (ways[1] + subtree_size[neighbor] * (n - subtree_size[neighbor])) % MOD;
        }
    }
}

void dfs2(int node, int parent) {
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            ways[neighbor] = (ways[node] + n - 2 * subtree_size[neighbor] + MOD) % MOD;
            dfs2(neighbor, node);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initial DFS from node 1 to compute subtree sizes and base ways for node 1
    dfs1(1, -1);

    // Secondary DFS to compute ways for all nodes
    dfs2(1, -1);

    // Output the result
    for (int i = 1; i <= n; ++i) {
        cout << ways[i] << " ";
    }
    cout << endl;

    return 0;
}
