#include<bits/stdc++.h>
using namespace std;
int Rotation(vector<int>&arr){
      int n = arr.size();
      int low = 0, high = n - 1;
      int ans = INT_MAX;
      int index = -1;

      while(low <= high){
            int mid = low + (high - low) / 2;
            // If the current search space is fully sorted
            if(arr[low] <= arr[high]){
                  ans = min(ans, arr[low]);
                  index = low;
                  break;
            }
            if(arr[low] <= arr[mid]){
                  ans = min(ans, arr[low]);
                  index = low;
                  low = mid + 1;
            }else{
                  high = mid - 1;
                  ans = min(ans, arr[mid]);
                  index = mid;
            }
      }
      return index;
}
int main(){
      vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
      cout << Rotation(arr) << endl;
}