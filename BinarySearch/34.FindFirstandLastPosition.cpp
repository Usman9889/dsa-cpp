#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Returns the last index where target appears
    in the sorted array.
    */
    int lastOccurrence(vector<int>& arr, int target) {
        // Left boundary of the current search range.
        int low = 0;

        // Right boundary of the current search range.
        int high = (int)arr.size() - 1;

        // Stores the rightmost matching index found so far.
        int answer = -1;

        // Keep searching while a valid range still exists.
        while (low <= high) {
            // Calculate the middle index safely.
            int mid = low + (high - low) / 2;

            // A match is found, so remember it and continue on the right side.
            if (arr[mid] == target) {
                answer = mid;
                low = mid + 1;
            } else if (arr[mid] < target) {
                // Values up to mid are too small, so move to the right half.
                low = mid + 1;
            } else {
                // The current value is too large, so search only on the left side.
                high = mid - 1;
            }
        }

        return answer;
    }
};

// Driver code starts
int main() {
    vector<int> arr = {1, 2, 4, 4, 4, 6, 8};
    int target = 4;

    Solution obj;
    cout << obj.lastOccurrence(arr, target) << endl;

    return 0;
}