// Brute force:
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n];
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      vector<int> ans;
      for(int i=0; i<n; i++){
            bool leader = true;
            for(int j=i+1; j<n; j++){
                  if(a[j] > a[i]){
                        leader = false;
                        break;
                  }
            }
            if(leader){
                  ans.push_back(a[i]);
            }
      }
    
}