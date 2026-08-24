#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      vector<int> arr(n);
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      int cnt = 0;
      for(int i=0; i<n; i++){
            if(arr[i] > arr[(i+1)%n]){
                  cnt++;
            }
      }      
      cout << (cnt <= 1 ? "YES" : "NO") << endl;
}
//Time complexity: O(n)
//Space complexity: O(1)