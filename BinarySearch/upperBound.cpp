#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int>arr ={1, 3, 5, 5, 9, 11};
      int x = 5;
      int low = 0, high = arr.size() - 1, n = arr.size();
      int answer = (int)arr.size();
      while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] > x){
                  answer = mid;
                  high = mid - 1;
            }else{
                  low = mid + 1;
            }
      }
      cout << answer;
      // cout << upper_bound(arr.begin(), arr.end(), x) - arr.begin() << endl;
}