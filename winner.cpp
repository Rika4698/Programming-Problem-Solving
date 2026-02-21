#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, int> scores;
    vector<pair<int, string>> players; // pair to store score and player name

    for (int i = 0; i < n; ++i) {
        string name;
        int score;
        cin >> name >> score;

        scores[name] += score;
        players.push_back({scores[name], name});
    }

    // Sort players by score in descending order
    sort(players.rbegin(), players.rend());

    // Output the name of the player with the highest score
    cout << players[0].second << endl;

    return 0;
}
