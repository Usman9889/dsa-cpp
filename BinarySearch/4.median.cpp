// Brute force:
// Time Complexity: O((N + M) x log(N + M)), because the final list containing all elements of size N+M is sorted.
// Space Complexity: O(N + M), because a separate list is created to store all elements which contains N + M elements.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Finds the median after putting both arrays
    into one combined sorted order.
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // This stores all values from both arrays in one place.
        vector<int> merged;

        for (int value : nums1) {
            merged.push_back(value);
        }

        for (int value : nums2) {
            merged.push_back(value);
        }

        // Sorting creates the final order needed for median calculation.
        sort(merged.begin(), merged.end());

        // This is the total number of values after both arrays are combined.
        int total = merged.size();

        // If total is odd, there is one exact middle element.
        if (total % 2 == 1) {
            return merged[total / 2];
        } else {
            // If total is even, the median is the average
            // of the two middle elements.
            return ((double)merged[total / 2 - 1] + merged[total / 2]) / 2.0;
        }
    }
};

// Driver code starts
int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution obj;
    cout << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
// Better Solution:
// Time Complexity: O((N + M) / 2), because only elements up to the middle position are processed.
// Space Complexity: O(1), because constant space is used.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Finds the median by simulating the merge process
    only until the middle position is reached.
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // These pointers track the next unused value in each array.
        int i = 0;
        int j = 0;

        // previous and current store the last two picked values.
        int previous = 0;
        int current = 0;

        // Only positions up to the middle can affect the median.
        int middle = (n + m) / 2;

        for (int count = 0; count <= middle; count++) {
            previous = current;

            // If both arrays still have values, choose the smaller one.
            if (i < n && j < m) {
                // nums1 is chosen when it has the smaller current value.
                if (nums1[i] <= nums2[j]) {
                    current = nums1[i];
                    i++;
                } else {
                    // nums2 is chosen because its current value is smaller.
                    current = nums2[j];
                    j++;
                }
            } else if (i < n) {
                // nums2 is finished, so the next value must come from nums1.
                current = nums1[i];
                i++;
            } else {
                // nums1 is finished, so the next value must come from nums2.
                current = nums2[j];
                j++;
            }
        }

        // If total is odd, current is the exact middle value.
        if ((n + m) % 2 == 1) {
            return current;
        } else {
            // If total is even, previous and current are the two middles.
            return ((double)previous + current) / 2.0;
        }
    }
};

// Driver code starts
int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution obj;
    cout << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
// Optimal Solution using Binary Search
// Time Complexity: O(log(min(N, M))), because binary search runs only on the smaller array.
// Space Complexity: O(1), because constant space is used.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Finds the median by binary searching the partition
    between the left half and the right half.
    */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary search should run on the smaller array.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        // This is how many elements must stay in the left half.
        int leftSize = (n + m + 1) / 2;

        int low = 0;
        int high = n;

        while (low <= high) {
            // cut1 means how many elements are taken from nums1.
            int cut1 = low + (high - low) / 2;

            // cut2 fills the remaining left-half positions from nums2.
            int cut2 = leftSize - cut1;

            // If cut1 is at the start, nums1 has no left value.
            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];

            // If cut1 is at the end, nums1 has no right value.
            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];

            // If cut2 is at the start, nums2 has no left value.
            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

            // If cut2 is at the end, nums2 has no right value.
            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // This condition means all left values are small enough.
            if (left1 <= right2 && left2 <= right1) {
                // If total length is odd, the median is the larger
                // value from the left side.
                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                } else {
                    // If total length is even, average the two
                    // values around the middle cut.
                    return (
                        (double)max(left1, left2) +
                        min(right1, right2)
                    ) / 2.0;
                }
            } else if (left1 > right2) {
                // Too many elements were taken from nums1,
                // so move its cut toward the left.
                high = cut1 - 1;
            } else {
                // Too few elements were taken from nums1,
                // so move its cut toward the right.
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

// Driver code starts
int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};

    Solution obj;
    cout << obj.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}