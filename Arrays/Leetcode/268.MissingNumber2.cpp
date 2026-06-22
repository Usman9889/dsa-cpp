#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n - 1];
      for(int i = 0; i < n - 1; i++){
            cin >> a[i];
      }
      //calculate sum of array of elements
      int sum = 0;
      for(int i = 0; i < n-1; i++){
            sum += a[i];
      }
      //calculate expected sum from 1 to n
      long long expSum = n * (n + 1) /2;

      cout << expSum - sum;
}