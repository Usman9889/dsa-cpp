#include<bits/stdc++.h>
using namespace std;
// Binary Search
// Time Complexity: O(log(n))
// Space Complexity: O(1)
int BinarySearch(vector<int>& arr, int x, int low, int high){

      while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[mid] == x){
                  return mid;
            }
            else if(arr[mid] > x) high = mid - 1;
            else low = mid + 1;
      }
      return -1;
}

int RecursiveCode(vector<int> &arr, int x, int low, int high){
      if(low > high) return -1;

      int mid = low + (high - low)/2;
      if(arr[mid] == x){
          return mid;
      } 
      else if(x > arr[mid]){
            return RecursiveCode(arr, x, mid + 1, high);
      }
      return RecursiveCode(arr, x, low, mid - 1);
}
int main(){

      vector<int> arr = {1, 3, 5, 7, 9, 11};
      int x = 7, low = 0, high = arr.size() - 1;
      cout << BinarySearch(arr, x, low, high) << endl;
      cout << RecursiveCode(arr, x, low, high) << endl;
      return 0;
}