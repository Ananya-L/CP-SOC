#include <iostream>
#include <vector>
using namespace std;

bool canBeSorted(vector<int>& a, int n) {
    for (int i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        bool possible = true;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] > a[i+1]) {
                int diff = a[i] - a[i+1];
                a[i] -= diff;
                a[i+1] += diff;
            }
        }
        
        if (canBeSorted(a, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
