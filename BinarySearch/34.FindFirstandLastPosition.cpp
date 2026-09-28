#include<bits/stdc++.h>
using namespace std;
int main(){
      vector<int> nums = {5, 7, 7, 8, 8, 10};
        int target = 8;
        int n = nums.size();
        int first = -1;
        int last = -1;
        //first occurance
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                first = mid;
                high = mid - 1; // search further left
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        //last occurance
        low = 0, high = n - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[mid] == target){
                last = mid;
                low = mid + 1; // search further right
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        cout << "First occurrence: " << first << endl;
        cout << "Last occurrence: " << last << endl;

    return 0;
}