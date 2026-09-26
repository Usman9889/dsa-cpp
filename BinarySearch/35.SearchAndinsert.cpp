#include<bits/stdc++.h>
using namespace std;
int main(){
      vector<int> arr = {1, 3, 5, 6};
      int x = 2;
      int n = arr.size();
      int low = 0, high = n - 1;
      // Starts as arr.size() so it remains correct when no lower bound exists.
      int answer = (int)arr.size();

      while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] >= x) {
                  answer = mid;
                  high = mid - 1;
            }else{
                  low = mid + 1;
            }
      }
      cout << answer;
}
