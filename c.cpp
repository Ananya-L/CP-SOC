#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#define int long long
using namespace std;

int T_T;

signed main() {
    cin >> T_T;
    while (T_T--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        int s = 0;

        // Input array and copy to c
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            c[i] = a[i];
        }

        // Sort array a
        sort(a.begin(), a.end());

        // Calculate prefix sums in b
        for (int i = 0; i < n; ++i) {
            b[i] = s;
            s += a[i];
        }

        // Create map to store final positions
        map<int, int> m;
        m[a[n - 1]] = n - 1;

        // Determine the appropriate position for each element
        for (int i = n - 2; i >= 0; --i) {
            if (b[i + 1] >= a[i + 1])
                m[a[i]] = m[a[i + 1]];
            else
                m[a[i]] = i;
        }

        // Output the results
        for (int i = 0; i < n; ++i)
            cout << m[c[i]] << " ";
        cout << endl;
    }
}
