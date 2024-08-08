#include <iostream>
using namespace std;
const long long MOD = 998244353; 

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int n; 
        cin >> n;
        
        long long left_sum = 0, right_sum = 0;
        long long factor = 1, factor_left = 1; 
        bool flag = true; 
        
        for (int i = 1; i <= n; i++) {
            int a; 
            cin >> a;
            
            left_sum += a;
            right_sum += a; 
            factor = (factor * 2) % MOD;
            
            if (left_sum >= 0) {
                factor_left = (factor_left * 2) % MOD; 
            }
            
            if (right_sum == -left_sum && right_sum != left_sum) {
                factor += factor_left; 
            }
            
            if (right_sum < -left_sum) {
                factor = factor_left;
            }
            
            right_sum = max(right_sum, -left_sum); 
        }
        
        cout << factor % MOD << endl; 
    }

    return 0;
}
