#include<bits/stdc++.h>
using namespace std;
//Brute Force Approach
// Time complexity: O(n^2)
// Space complexity: O(1)
int subarraySumK(vector<int>& nums, int k) {
      int n = nums.size();
      int cnt = 0;

      for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                  sum += nums[j];
                  if(sum == k){
                        cnt++;
                  }
            }
      }
      return cnt;
}
// Optimal Approach using Prefix Sum + Hash Map
// Time complexity: O(n)
// Space complexity: O(n)
int OptimalSubarraySumK(vector<int>& arr, int k) {
      int n = arr.size();
      unordered_map<int, int>mpp;
      int prefixSum = 0, cnt = 0;
      mpp[0] = 1;

      for(int i=0; i<n; i++){
            prefixSum += arr[i];

            int target = prefixSum - k;

            if(mpp.find(target) != mpp.end()){
                  cnt += mpp[target];
            }
            mpp[prefixSum]++;
      }
      return cnt;
}
int main(){
      vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
      int k = 3;
      int result = subarraySumK(arr, k);
      cout << "Number of subarrays with sum " << k << ": " << result << endl;
      int ans = OptimalSubarraySumK(arr, k);
      cout << "Number of subarrays with sum optimal " << k << ": " << ans << endl;
}