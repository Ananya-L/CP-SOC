#include <iostream>
#include <vector>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases; 

    while (test_cases--) {
        int array_length;
        cin >> array_length; 

        vector<int> array(array_length + 1);
        for (int i = 1; i <= array_length; ++i) {
            cin >> array[i]; 
        }

        bool is_possible = true;
        if (array_length % 2 == 0) {
            long long total_sum = 0;
            for (int i = 1; i <= array_length; ++i) {
                if (i % 2 == 1) {
                    total_sum += array[i]; 
                } else {
                    total_sum -= array[i]; 
                }
            }
            if (total_sum > 0) {
                is_possible = false;
            }
        }

        if (is_possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
