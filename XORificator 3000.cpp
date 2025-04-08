#include <algorithm>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <cmath>
#include <map>
#include <fstream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <unordered_set>
#include <random>
#include <unordered_map>
#include <cassert>
#include <valarray>
#include <chrono>
#include <bitset>
#include <chrono>

using namespace std;

using ll = long long;
#define int ll
void solve() {
    auto xo = [&] (auto self, ll r) -> ll {
        if (!r) return 0;
        if (r == 1) return 1;
        int l = 0;
        for (int i = 0; i < 62; ++i) {
            if ((r >> i) & 1) l = i;
        }
        ll res = 0;
        if (l == 1) res = 1;
        if (!(r & 1)) res ^= (1ll << l);
        res ^= self(self, r - (1ll << l));
        return res;
    };
    auto get = [&] (auto self, ll r, ll I, ll k) -> pair<ll, ll> {
        ll ans = 0;
        int l = -1;
        for (int i = 0; i < 62; ++i) {
            if ((r >> i) & 1) l = i;
        }
        if (l == -1 || l < I) {
            if (k <= r) {
                return make_pair(k, 1);
            } else return make_pair(0, 0);
        }
        else if (l == I) {
            int ev = 0;
            ans ^= k; ++ev;
            if ((1ll << l) + k <= r) {
                ans ^= ((1ll << l) + k); ++ev;
            }
            return make_pair(ans, ev % 2);
        } else {
            int ev = 0;
            auto res = self(self, r - (1ll << l), I, k);
            if (l - I == 1) {
                ans ^= (1ll << (l - 1));
                ans ^= res.first;
                ev = res.second;
            }
            else {
                ans ^= res.first;
                ev = res.second;
            }
            if (ev & 1) ans ^= (1ll << l);
            return make_pair(ans, ev);
        }
    };
    ll l, r, i, k; cin >> l >> r >> i >> k;
    cout << (get(get, r, i, k).first ^ get(get, l - 1, i, k).first ^ xo(xo, r) ^ xo(xo, l - 1)) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
