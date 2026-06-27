// Approaches:
// 1. Brute Force:

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
      int cnt = 0;

      for(int j=0; j<n; j++){
            if(a[j] == a[i]){
                  cnt++;
            }
      }
      if(cnt > n/2){
            cout << a[i];
            break;
      }
    }
}
// 2. Better (Hashing/hashmap)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> mpp;

    for(int i=0; i<n; i++){
      mpp[a[i]]++;
    }

    for(auto it : mpp){
      if(it.second > n/2){
            cout << it.first;
      }
    }
}