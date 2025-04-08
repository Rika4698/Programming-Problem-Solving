#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char s_file, t_file;
    int s_rank, t_rank;
    cin >> s_file >> s_rank >> t_file >> t_rank;

    int dx = abs(s_file - t_file);
    int dy = abs(s_rank - t_rank);

    int moves = max(dx, dy);
    cout << moves << endl;

    while (dx > 0 || dy > 0) {
        if (s_file < t_file && dx > 0) {
            cout << "R";
            s_file++;
            dx--;
        } else if (s_file > t_file && dx > 0) {
            cout << "L";
            s_file--;
            dx--;
        }

        if (s_rank < t_rank && dy > 0) {
            cout << "U";
            s_rank++;
            dy--;
        } else if (s_rank > t_rank && dy > 0) {
            cout << "D";
            s_rank--;
            dy--;
        }
        cout << endl;
    }

    return 0;
}

