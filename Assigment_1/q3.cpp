#include<iostream>
#include<vector>
using namespace std;

void find_numbers(vector<int>& numbers, int target, int mid1, int mid2) {
    bool found = false;
    while (mid1 >= 0 && mid2 < numbers.size()) {
        if (numbers[mid1] + numbers[mid2] < target) {
            mid2++;
        } else if (numbers[mid1] + numbers[mid2] > target) {
            mid1--;
        } else {
            cout << mid1+1<< " " << mid2+1<< endl;
            found = true;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n, target;
        cin >> n >> target;
        vector<int> numbers(n);
        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }
        int half = target / 2;
        bool breaker = false;
        int i;
        for (i = 0; i < n && numbers[i] <= half; i++) {
            if (numbers[i] == half) {
                if (target > 0) {
                    find_numbers(numbers, target, i, i + 1);
                } else {
                    find_numbers(numbers, target, i - 1, i);
                }
                breaker = true;
                break;
            }
        }
        if (!breaker) {
            find_numbers(numbers, target, i - 1, i);
        }
    }
}
