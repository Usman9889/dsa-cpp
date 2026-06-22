#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n - 1];
      for(int i = 0; i < n - 1; i++){
            cin >> a[i];
      }
      vector<int> hash(n + 1, 0);

      for(int i = 0; i < n - 1; i++){
            hash[a[i]]++;
      }

      for(int i = 1; i <= n; i++){
            if(hash[i] == 0){
                  cout << i;
                  break;
            }
      }
}