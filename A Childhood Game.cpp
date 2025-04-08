#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long n;
        string first;
        cin >> n >> first;


        if (first == "Alice") {
            if (n % 3 == 1) {
                cout << "Case " << t << ": "<<"Bob" << endl;
            } else {
                cout << "Case " << t << ": "<<"Alice" << endl;
            }
        }

        else if (first == "Bob") {
            if (n % 3 == 0) {
                cout << "Case " << t << ": "<<"Alice" << endl;
            } else {
                cout << "Case " << t << ": "<<"Bob" << endl;
            }
        }
    }

    return 0;
}
