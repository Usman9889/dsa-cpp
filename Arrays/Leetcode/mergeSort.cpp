#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n log n)
// Space Complexity: O(n)

void merge(vector<int> &arr, int low, int mid, int high) {

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    // Compare elements from both halves
    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Remaining elements of left half
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Remaining elements of right half
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back into original array
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {

    // Base case
    if (low >= high)
        return;

    int mid = (low + high) / 2;

    // Sort left half
    mergeSort(arr, low, mid);

    // Sort right half
    mergeSort(arr, mid + 1, high);

    // Merge both sorted halves
    merge(arr, low, mid, high);
}

int main() {

    vector<int> arr = {12, 11, 13, 5, 6, 7};

    mergeSort(arr, 0, arr.size() - 1);

    // Print sorted array
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}