//Brute Force Approach
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      vector<int> arr(n);
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      sort(arr.begin(), arr.end());
      cout << arr[n-1] << endl;
}


// Optimal Approach
#include<iostream>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      int max = arr[0];
      for(int i=1; i<n; i++){
            if(arr[i] > max){
                  max = arr[i];
            }
      }
      cout << max << endl;

}