#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int max_wins(vector<int>& powers, int D) {
int wins = 0;
    sort(powers.begin(), powers.end(), greater<int>());

    for (int i = 0; i < powers.size(); ++i) {
        if (powers[i] > D) {
            wins++;
        } else {
            break; // No need to check further, as remaining players' powers will be less than D
        }
    }
    int i = wins;
    int last = powers.size()-1;
    while(i<last) {
        int large = powers[i];
        int number_of_players = floor(double(D)/large); // Excluding the top player
        if (number_of_players <= last-i) {
            last -= number_of_players;
            i++;
            wins++;
        } else {
            break; // No more eliminations possible
        }
    }

    return wins;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> powers(N);
    for (int i = 0; i < N; ++i) {
        cin >> powers[i];
    }

    cout << max_wins(powers, D) << endl;
    return 0;
}
