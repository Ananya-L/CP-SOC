#include <iostream>
#include <algorithm> 
using namespace std;

int findMin(int* arr, int start, int stop) {
    switch(stop - start) {
        case 0:
            return arr[start];
        case 1:
            return min(arr[start], arr[stop]);
        case 2:
            return min(min(arr[start], arr[start + 1]), arr[stop]);
        default:
            int middle_index = start + (stop - start) / 2;
            if (arr[start] <= arr[middle_index]) {
                if (arr[middle_index] <= arr[stop]) {
                    return arr[start];
                } else {
                    return findMin(arr, middle_index + 1, stop);
                }
            } else {
                if (arr[middle_index] >= arr[stop]) {
                    return findMin(arr, middle_index + 1, stop);
                } else {
                    return findMin(arr, start, middle_index);
                }
            }
    }
}

int main() {
    int t;
    cin>>t;
    for (int j=0; j<t;j++) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << findMin(arr, 0, n - 1) << endl;
    }

}
