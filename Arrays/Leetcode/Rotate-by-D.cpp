// Brute Force Approach:
// Right Rotation: We store the last k elements of the array into a temporary array. Then we shift all the other elements (n-k elements) to the right by k positions. Finally, we place the elements from the temporary array at the beginning of the original array. This achieves a right rotation by k positions.
// Left Rotation: We store the first k elements in a temporary array. Then we shift the remaining n-k elements to the left by k positions. Finally, we copy the elements from the temporary array to the end of the array. This achieves a left rotation by k positions.

// Time Complexity: O(n), We are performing a constant number of linear operations copying `k` elements and shifting up to `n-k` elements.
// Space Complexity: O(k) ,A temporary array of size `k` is used to store either the first `k` or last `k` elements depending on the direction of rotation.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int d;
    cin >> d;
    int temp[d];

    for (int i = 0; i < d; i++) {
        temp[i] = a[i];

    }

    for (int i = d; i < n; i++) {
        a[i - d] = a[i];
    }

    for (int i = n - d; i < n; i++) {
        a[i] = temp[i - (n - d)];

    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

// Optimal Approach: Instead of simulating each rotation one by one, we can get the rotated array in-place by reversing specific parts of the array. This works because rotating is just rearranging sections of the array.

// Time Complexity: O(N), We reverse parts of the array each reverse takes linear time. So total work is 3 × O(N) = O(N).
// Space Complexity: O(1) All modifications are done in-place, using only a few temporary variables.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to reverse a subarray from index start to end
    void reverseArray(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

    // Function to rotate array left or right by k steps
    vector<int> rotateArray(vector<int>& nums, int k, string direction) {
        int n = nums.size();

        // Edge case: empty or no rotation
        if (n == 0 || k == 0) return nums;

        // Normalize k
        k = k % n;

        if (direction == "right") {
            // Step 1: Reverse the whole array
            reverseArray(nums, 0, n - 1);

            // Step 2: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 3: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);
        } 
        else if (direction == "left") {
            // Step 1: Reverse first k elements
            reverseArray(nums, 0, k - 1);

            // Step 2: Reverse remaining n-k elements
            reverseArray(nums, k, n - 1);

            // Step 3: Reverse the whole array
            reverseArray(nums, 0, n - 1);
        }

        return nums;
    }
};

// Driver code
int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string dir = "right";

    vector<int> result = sol.rotateArray(nums, k, dir);

    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
