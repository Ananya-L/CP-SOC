#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int t;
    cin >> t;

    for (int r = 0; r < t; r++) {
        int n;
        cin >> n;
        int arr[2 * n];
        for (int i = 0; i < 2 * n; i++) {
            cin >> arr[i];
        }
        mergeSort(arr, 0, 2 * n - 1);
        
        // Calculate the minimum path length
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[2 * i + 1] - arr[2 * i];
        }
        cout << sum << endl;

        // Output the pairs
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " " << arr[2 * n - 1 - i] << endl;
        }
    }
    return 0;
}
