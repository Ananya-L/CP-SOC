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
        
        vector<int> a(n + 1); 
        
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        
        long long sum = 0, res = 0;
        
       
        for (int i = 1; i <= n; ++i) {
            sum += a[i];
            res = min(res, sum);
        }
        
     
        cout << sum - 2 * res << endl;
    }
    
    return 0;
}
