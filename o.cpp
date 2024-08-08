#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr.begin(), arr.end());
        int currentSum = 1;
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] > currentSum) {
                possible = false;
                break;
            }
            if (i != 0)
                currentSum += arr[i];
        }
        
        if (possible)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
