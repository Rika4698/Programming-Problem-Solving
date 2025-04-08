#include <bits/stdc++.h>


using namespace std;
typedef long long ll;
int main() {
    int H, W;
    cin >> H >> W;

    int min_side = min(H, W);
    ll total = 0;

    for (int k = 1; k <= min_side; k++) {
        total = total+(H - k + 1) * (W - k + 1);
    }

    cout << total << endl;
    return 0;
}

