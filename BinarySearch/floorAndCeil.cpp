#include<bits/stdc++.h>
using namespace std;

int main(){
      vector<int> arr = {1, 3, 5, 7, 9, 11};
      int x = 4;
      int n = arr.size();
      int floor = -1; 
      int ceil = -1;
      int low = 0, high = n - 1;

      while(low <= high){
            int mid = low + (high - low) / 2;

            if(arr[mid] == x ){
                  floor = arr[mid];
                  ceil = arr[mid];
            }else if( arr[mid] < x){
                  //arr[mid] is posible floor
                  floor = arr[mid];
                  low = mid + 1;
            }else{
                  //arr[mid] is posible ceil
                  ceil = arr[mid];
                  high = mid - 1;
            }
      }
      cout << floor << ", " << ceil;
}