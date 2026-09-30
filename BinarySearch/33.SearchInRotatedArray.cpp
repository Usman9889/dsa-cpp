#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    int target = 1;

    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Target found
        if (arr[mid] == target) {
            cout << mid;
            return 0;
        }

        // Left half is sorted
        if (arr[low] <= arr[mid]) {

            // Is target inside the sorted left half?
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        // Right half is sorted
        else {

            // Is target inside the sorted right half?
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    cout << -1;
    return 0;
}