#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
      int target = 0;
      int n = arr.size();

      // Left boundary of the current search range.
        int low = 0;
 
        // Right boundary of the current search range.
        int high = (int)arr.size() - 1;
 
        // Keep searching while a valid range still exists.
        while (low <= high) {
            // Calculate the middle index safely.
            int mid = low + (high - low) / 2;
 
            // The target is found at the middle position.
            if (arr[mid] == target) {
                  cout << true;
                return 0;
            }
 
            // Duplicates at both ends hide which half is sorted.
            if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
                low++;
                high--;
            }
            // The left half is normally sorted.
            else if (arr[low] <= arr[mid]) {
                // The target lies inside the sorted left half.
                if (arr[low] <= target && target < arr[mid]) {
                    high = mid - 1;
                } else {
                    // The target must lie in the other half.
                    low = mid + 1;
                }
            } else {
                // The right half must be normally sorted here.
                if (arr[mid] < target && target <= arr[high]) {
                    low = mid + 1;
                } else {
                    // The target must lie in the other half.
                    high = mid - 1;
                }
            }
        }
      cout << false;
}