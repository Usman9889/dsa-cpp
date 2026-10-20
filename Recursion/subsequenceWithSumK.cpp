#include<bits/stdc++.h>
using namespace std;
bool printSubsequences(int index, vector<int>&arr, int sum, int k ){
      //base case
      if(index == arr.size()){
            return sum == k;
      }
      //Pick the current element
      
      if(printSubsequences(index + 1, arr, sum +arr[index], k)){
            return true;
      }
      
      //Do not pick the current element
      if(printSubsequences(index + 1, arr, sum,  k)){
            return true;
      }
      return false;
}
int main(){
      vector<int> arr = {3, 1, 2};
      int k = 3;
      
      if(printSubsequences(0, arr, 0, k)){
            cout << "True";
      }else{
            cout << "False";
      }
      return 0;
}