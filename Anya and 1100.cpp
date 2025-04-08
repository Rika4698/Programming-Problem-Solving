#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Helper function to check if "1100" exists in a specific position
bool is1100(const string& s, int pos) {
    return pos >= 0 && pos + 3 < s.size() && s[pos] == '1' && s[pos + 1] == '1' && s[pos + 2] == '0' && s[pos + 3] == '0';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int q;
        cin >> q;

        // Count initial "1100" occurrences
        int count_1100 = 0;
        for (int i = 0; i + 3 < s.size(); ++i) {
            if (is1100(s, i)) {
                count_1100++;
            }
        }

        // Process each query
        while (q--) {
            int i;
            char v;
            cin >> i >> v;
            --i; // Convert to 0-based index

            // Update the count for "1100" before making the change
            for (int j = i - 3; j <= i; ++j) {
                if (is1100(s, j)) {
                    count_1100--;
                }
            }

            // Apply the change
            s[i] = v;

            // Update the count for "1100" after the change
            for (int j = i - 3; j <= i; ++j) {
                if (is1100(s, j)) {
                    count_1100++;
                }
            }

            // Output result for the current query
            if (count_1100 > 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}

