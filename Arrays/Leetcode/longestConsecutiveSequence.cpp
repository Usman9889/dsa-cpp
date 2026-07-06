//Brute Force:
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& a, int n){
      
      for(int i=0; i<a.size(); i++){
            if(a[i] == n){
                  return true;
            }
      }
      return false;
}
int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      
      if(a.size() == 0){
            cout << 0 << endl;
            return 0;
      }
      int longest = 1;
      for(int i=0; i<n; i++){
            int x = a[i];
            int cnt = 1;
            while(linearSearch(a, x + 1)){
                  x = x + 1;
                  cnt += 1;
            }
            longest = max(longest, cnt);
      }
      cout << longest << endl;
}