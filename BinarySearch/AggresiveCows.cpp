// Aggressive Cows: Maximize the Minimum Distance
#include<bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>&stalls, int dist, int k){
      int n = stalls.size();
      int cntCows = 1, LastPosition = stalls[0];
      for(int i=1; i<n; i++){
            if(stalls[i] - LastPosition >= dist){
                  cntCows++;
                  LastPosition = stalls[i];
            }
            if(cntCows >= k){
                  return true;
            }
      }
      return false;
}
// Brute force 
// Time Complexity: O(nlogn + n*d) // d = (max - min) stall position.
//  Space Complexity: O(1)
int aggressiveCows(vector<int>& stalls, int k) {
      sort(stalls.begin(), stalls.end());
      int n = stalls.size();
      int maxDist = stalls[n - 1] - stalls[0];

      for(int dist=1; dist<=maxDist; dist++){
            if(!canPlace(stalls, dist, k)){
                  return dist - 1;
            }
      }
      return maxDist;
}
// Optimal: Binary Search
// Time Complexity: O(nlogn + n log d) // d = (max - min) stall position
// Space Complexity: O(1)
int aggresiveCowsOptimal(vector<int>&stalls, int k){
      int n = stalls.size();
      sort(stalls.begin(), stalls.end());
      int low = 1, high = stalls[n - 1] - stalls[0];
      int ans = -1;
      while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(stalls, mid, k)){
                  ans = mid;
                  low = mid + 1;
            }else{
                  high = mid - 1;
            }
      }
      return ans;
}
int main(){
      vector<int> stalls = {1, 2, 4, 8, 9};

      int k = 3;
      cout << aggressiveCows(stalls, k) << endl;
      cout << aggresiveCowsOptimal(stalls, k) << endl;
}