//brute force
//Time complexity: O(nlogn)
//Space complexity: O(1)
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
      
      for(int i=n-2; i>=0; i--){
            if(arr[i] != arr[n-1]){
                  cout << arr[i] << endl;
            }
      }
}

//Better(Two pass search)
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      vector<int> arr(n);
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      int largest = -1, secondLargest = -1; 
      //Finding the largest element
      for(int i=0; i<n; i++){
            if(arr[i] > largest){
                  largest = arr[i];
            }
      }
      //Finding the second largest element
      for(int i=0; i<n; i++){
            if(arr[i] > secondLargest && arr[i] < largest){
                  secondLargest = arr[i];
            }
      }
      cout << secondLargest << endl;
}