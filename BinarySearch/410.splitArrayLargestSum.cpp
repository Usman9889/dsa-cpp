#include <bits/stdc++.h>
using namespace std;

bool canSplit(vector<int>& nums, int maxAllowed, int k){
    // At least one subarray is needed when nums is not empty.
    int subarray = 1;
    
    // This stores the sum of the current subarray.
    int currentSum = 0;
    
    for(int num : nums){
        if(currentSum + num <= maxAllowed){
            currentSum += num;
        }else{
            subarray++;
            currentSum = num;
        }
    }
    return subarray <= k;
}
// Brute Force: Linear Search
// Time Complexity: O(N x (Sum - Max + 1)), N is the length of nums array, because every possible maximum sum may scan the whole array.

// Space Complexity: O(1), because constant space is used.
int splitArrayBrute(vector<int>& nums, int k){
    
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    for(int maxAllowed = low; maxAllowed <= high; maxAllowed++){
        if(canSplit(nums, maxAllowed, k)){
            return maxAllowed;
        }
    }
    return high;
}

// Optinal(Binary search)
// Time Complexity:O(N x log2(Sum - Max + 1)), N is the length of nums array, because every binary-search check scans the array once. Binary search has a range of Sum-Max+1 giving complexity of log2(Sum-Max+1).
// Space Complexity: O(1), because constant space is used.
int splitArray(vector<int>& nums, int k){
    
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(canSplit(nums, mid, k)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
int main() {
	vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    
    cout <<"Brute force: "<< splitArrayBrute(nums, k) << endl;
    cout << splitArray(nums, k) << endl;

}
