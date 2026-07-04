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
      for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
      }
}

// Optimal
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
      int maxFromRight = INT_MIN;
      
      for(int i=n-1; i>=0; i--){
            if(a[i] > maxFromRight){
                  ans.push_back(a[i]);
            }
            maxFromRight = max(maxFromRight, a[i]);
      }
      reverse(ans.begin(), ans.end());
      for(int i=0; i<ans.size(); i++){
            cout << ans[i] << " ";
      }
}