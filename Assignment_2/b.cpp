#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        unordered_map<int, int> count_map;
        for (int i = 0; i < n; ++i) {
            int difference = a[i] - i;
            count_map[difference]++;
        }

        int max_frequency = 0;
        for (const auto& entry : count_map) {
            if (entry.second > max_frequency) {
                max_frequency = entry.second;
            }
        }

        cout << max_frequency << '\n';
    }

    return 0;
}
