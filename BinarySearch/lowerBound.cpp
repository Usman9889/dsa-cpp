#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int> arr= {1, 3, 5, 7, 9, 11};
      int x = 5;

      // cout << lower_bound(arr.begin(), arr.end(), x) - arr.begin() << endl; //STL
      int n = arr.size();

      // Starts as arr.size() so it remains correct when no lower bound exists.
      int answer = (int)arr.size();

      int low = 0, high = n - 1;
      while(low <= high){
            int mid = low + (high-low) / 2;
            if(arr[mid] >= x){
                  answer = mid;
                  high = mid - 1;
            }else{
                  low = mid + 1;
            }
      }
      cout << answer;
}