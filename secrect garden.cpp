// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx2")
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// #define int long long
#define endl '\n'

using namespace std;
using pii = pair<int, int>;
using tup = tuple<int, int, int>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// template <class T> using ordered_set = tree<T, null_type,
//                          less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9;
const int mod = 1000000007;
const double eps = 1e-9;
const int N = 200005;

void preprocess() {}

struct Node {
    vector<pii> v;

    Node() {}
    Node(int val) { v = {{1, val}}; }
};

Node merge(Node a, Node &b) {
    for(auto [y, x] : b.v) {
        bool f = 0;
        for(auto &[y2, x2] : a.v) {
            if(x == x2) {
                f = 1;
                y2 += y;
            }
        }
        if(!f) a.v.push_back({y, x});
    }
    sort(a.v.begin(), a.v.end(), greater<pii>());
    while(a.v.size() > 5) a.v.pop_back();
    return a;
}

Node tr[N * 4];
int a[N];

void build(int node, int b, int e) {
    if(b == e) {
        tr[node] = Node(a[b]);
        return;
    }
    int mid = b + e >> 1;
    build(node*2, b, mid);
    build(node*2+1, mid+1, e);

    tr[node] = merge(tr[node*2], tr[node*2+1]);
}

Node query(int node, int b, int e, int i, int j) {
    if(i > e || j < b) return Node();
    if(b >= i && e <= j) return tr[node];

    int mid = b + e >> 1;
    Node left = query(node*2, b, mid, i, j);
    Node right = query(node*2+1, mid+1, e, i, j);

    return merge(left, right);
}


void solve(int tc) {
    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) cin >> a[i];
    build(1, 1, n);

    while(q--) {
        int l, r;
        cin >> l >> r;
        Node res = query(1, 1, n, l, r);
        int ans = inf;

        for(auto [y, x] : res.v)
            if(y * 3 > r-l+1) ans = min(ans, x);
        if(ans == inf) ans = -1;

        cout << ans << endl;
    }
}

int32_t main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cout.precision(10);

    preprocess();

    int T = 1;
    // cin >> T;

    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}
