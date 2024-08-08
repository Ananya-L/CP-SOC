#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> colors(n + 1);
        vector<int> dp(n + 1, -INF);
        int maxBallsRemoved = 0;

        for (int i = 1; i <= n; i++) {
            cin >> colors[i];
        }

        for (int i = 1; i <= n; i++) {
            int color = colors[i];
            int prevMax = dp[color];
            dp[color] = max(dp[color], maxBallsRemoved - i);
            maxBallsRemoved = max(maxBallsRemoved, prevMax + i + 1);
        }

        cout << maxBallsRemoved << endl;
    }
    return 0;
}
