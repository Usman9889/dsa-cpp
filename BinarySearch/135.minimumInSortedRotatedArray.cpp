#include<bits/stdc++.h>
using namespace std;
//identify sorted half
//sorted half may or may not have the answer
//take the minimun from sorted half and eleminate 
int search(vector<int>& nums) {
      int n = nums.size();
      int low = 0, high = n - 1;
      int ans = INT_MAX;

      
      while(low <= high){
            int mid = low + (high - low) / 2;
            
            if(nums[low] <= nums[high]) {
            ans = min(ans, nums[low]);
            break;
            }
            //left sorted
            if(nums[low] <= nums[mid]){
                  ans = min(ans, nums[low]);
                  low = mid + 1;
            }else{
                  ans = min(ans, nums[mid]);
                  high = mid - 1;
            }
      }
      return ans;
}
int main(){
      vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
      cout << search(arr) << endl;
}