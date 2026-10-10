#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(k × N), where N is the number of given gas stations. We loop through all N-1 gaps exactly k times, which makes the approach very slow for large inputs.

// Space Complexity: O(N), as we allocate an additional array of size N-1 to track the stations placed in each gap.
class Solution {
public:
    // Manually scans the array k times to find and divide the largest current gap
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        // Array to track how many new stations are added in each original gap
        vector<int> howMany(n - 1, 0);
        
        // Place k stations one by one in the largest available gaps
        for (int stations = 1; stations <= k; stations++) {
            long double maxSection = -1.0;
            int maxIndex = -1;
            
            // Scan all gaps to find the current maximum section length
            for (int i = 0; i < n - 1; i++) {
                long double diff = arr[i + 1] - arr[i];
                long double sectionLength = diff / (long double)(howMany[i] + 1);
                
                // Keep track of the largest gap found
                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxIndex = i;
                }
            }
            
            // Add one station to the largest found gap
            howMany[maxIndex]++;
        }
        
        long double maxAns = -1.0;
        
        // Calculate the final maximum distance across all sections
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength = diff / (long double)(howMany[i] + 1);
            maxAns = max(maxAns, sectionLength);
        }
        
        return maxAns;
    }
};

// Driver code starts here
int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
// better approach: max heap(priority queue)

// Time Complexity: O((N + K) x log2 N). We take N x log N time to build the initial heap of gaps. Then, extracting and inserting back into the heap takes log2 N time, and we do this exactly k times.

// Space Complexity: O(N), to maintain the howMany array and the priority queue which stores all the segment distances.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
       Utilizes a max heap to continuously retrieve and divide
       the largest available distance segment efficiently
    */
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        int n = arr.size();
        // Array to track how many new stations are added in each original gap
        vector<int> howMany(n - 1, 0);
        
        // Max heap to store pairs of current gap distance and its original index
        priority_queue<pair<long double, int>> pq;
        
        // Populate the heap with the initial gaps between stations
        for (int i = 0; i < n - 1; i++) {
            pq.push({arr[i + 1] - arr[i], i});
        }
        
        // Place k stations one by one by always splitting the largest gap
        for (int stations = 1; stations <= k; stations++) {
            // Retrieve the maximum gap from the top of the heap
            auto top = pq.top();
            pq.pop();
            int secIndex = top.second;
            
            // Add a station to this specific gap segment
            howMany[secIndex]++;
            
            // Calculate the newly divided segment length
            long double originalDiff = arr[secIndex + 1] - arr[secIndex];
            long double newSectionLen = originalDiff / (long double)(howMany[secIndex] + 1);
            
            // Reinsert the reduced gap back into the heap for future operations
            pq.push({newSectionLen, secIndex});
        }
        
        // The maximum distance is guaranteed to be at the top of the heap
        return pq.top().first;
    }
};

// Driver code starts here
int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}

// Optimal Approach
// The priority queue method is highly inefficient for extremely large values of k. Simulating the placements step-by-step by popping and pushing to a heap repeatedly will result in a Time Limit Exceeded error. We can optimize this by bypassing the step-by-step simulation entirely and using Binary Search on Answers to directly find the final maximum distance.

// Time Complexity: O(N x log2(Max / 1e-6)), where N is the length of the array and Max is the highest starting distance gap. The binary search halves the precision bracket logarithmically, and traversing the array occurs inside each precision step.

// Space Complexity: O(1), no extra structures or arrays are created. The process runs perfectly using basic numeric pointers and basic math variables.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
       Helper function to verify how many gas stations are required
       to enforce a specific maximum distance rule across all gaps
    */
    int numberOfGasStationsRequired(vector<int>& arr, long double dist) {
        int required = 0;
        
        // Check every existing gap between stations
        for (int i = 0; i < arr.size() - 1; i++) {
            // Count how many sections of 'dist' length fit inside the gap
            required += (int)((arr[i + 1] - arr[i]) / dist);
        }
        
        return required;
    }

    /*
       Optimal approach using binary search to guess the maximum distance
       and validate it against our allowed station capacity
    */
    long double minimiseMaxDistance(vector<int> &arr, int k) {
        long double low = 0;
        long double high = 0;
        
        // Find the absolute maximum gap to act as the upper search boundary
        for (int i = 0; i < arr.size() - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }
        
        // Loop runs until the search boundaries are precise to 6 decimal places
        while (high - low > 1e-6) {
            // Guess the middle distance
            long double mid = low + (high - low) / 2.0;
            
            // Validate if the guessed distance fits within our allowed k stations
            if (numberOfGasStationsRequired(arr, mid) > k) {
                // Too many stations needed, distance is too strict
                low = mid;
            } else {
                // Feasible distance, attempt to restrict it further
                high = mid;
            }
        }
        
        // Return the precise finalized upper bound
        return high;
    }
};

// Driver code starts here
int main() {
    Solution obj;
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = obj.minimiseMaxDistance(arr, k);
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}