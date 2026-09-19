 #include <bits/stdc++.h>
 using namespace std;

// Brute Force 
// Time complexity: O(n^2)
// Space complexity: O(1)
 vector<int> majorityElementTwo(vector<int>& nums) {
        // Size of the array
        int n = nums.size(); 
        // List of answers
        vector<int> result;

         for (int i = 0; i < n; i++) {
        /*Checking if nums[i] is not 
        already part of the answer*/
        if (result.size() == 0 || result[0] != nums[i]) {
            
            int cnt = 0;
            
            for (int j = 0; j < n; j++) {
                // counting the frequency of nums[i]
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }
            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                result.push_back(nums[i]);
        }
        //if result size is equal to 2 break out of loop
        if (result.size() == 2) break;
    }
    //return the majority elements
    return result;
    }
// Better Approach (Hashing)
// Time complexity: O(n log n)
// Space complexity: O(n)
vector<int> betterApproach(vector<int>& arr) {
      int n = arr.size();

      //list of answers
      vector<int> ans;

      int majority = n/3 + 1;

      map<int,int> mpp;
      for(int i=0; i<n; i++){
            mpp[arr[i]]++;

            if(mpp[arr[i]] == majority){
                  ans.push_back(arr[i]);
            }
            if(ans.size() == 2) break;
      }
      return ans;
      
}

// Optimized Approach(Boyer-Moore Voting Algorithm)
// Time complexity: O(n)
// Space complexity: O(1)
vector<int> optimizedApproach(vector<int>& arr) {
      int n = arr.size();
      int cnt1 = 0, cnt2 = 0;
      int el1 = INT_MIN, el2 = INT_MIN;

      for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != arr[i]){
                  cnt1 = 1;
                  // Initialize el1 as arr[i]
                  el1 = arr[i]; 
            }
            else if(cnt2 == 0 && el2 != arr[i]){
                  cnt2 = 1;
                  // Initialize el2 as arr[i]
                  el2 = arr[i];
            }
            else if (el1 == arr[i]) cnt1++;
            else if (el2 == arr[i]) cnt2++;
            else{
                  cnt1--;
                  cnt2--;
            }
      }
      cnt1 = 0, cnt2 = 0;
      for(int i=0; i<n; i++){
            if(arr[i] == el1) cnt1++;
            if(arr[i] == el2) cnt2++;
      }
      vector<int> ans;
      int mini = n/3 + 1;
      if(el1 == mini) ans.push_back(el1);
      if(el2 == mini && el1 != el2) ans.push_back(el2);
      return ans;
}
    int main(){
        vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
        //brute force
        vector<int> result = majorityElementTwo(nums);
        for (auto x : result) {
            cout << x << " ";
        }
        cout << endl;
        //better
        vector<int> ans = betterApproach(nums);
        for(auto it : ans){
            cout << it << " ";
        }
        cout << endl;

      //   Optimal
      vector<int> res = optimizedApproach(nums);
      for(auto it : ans){
            cout << it << " ";
        }
        return 0;
    }
