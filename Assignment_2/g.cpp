#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int greetings = 0;
        vector<pair<int, int>> difference(n);
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            difference[i] = {b - a, b};
        }

        sort(difference.begin(), difference.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;
        });

        for (int i = 0; i < n; i++) {
            auto it = upper_bound(difference.begin(), difference.end(), make_pair(difference[i].first, 0), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.first < b.first;
            });

            if (it == difference.end()) {
                break;
            }

            int index = it - difference.begin();
            for (int j = index; j < n; j++) {
                if (difference[i].second >= difference[j].second - difference[j].first + difference[i].first && difference[i].second <= difference[j].second) {
                    greetings++;
                }
            }
        }
        cout << greetings << endl;
    }
    return 0;
}
