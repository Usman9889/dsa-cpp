//Optimal

#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n];
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      
      int index = -1;
      for(int i=n-2; i>=0; i--){
            if(a[i] < a[i+1]){
                  index = i;
                  break;
            }
      }
      if(index == -1){
            reverse(a, a+n);
            //or reverse(a.begin(), a.end());
            for(int i=0; i<n; i++){
                  cout << a[i] << " ";
            }
            return 0;
      }
      for(int i=n-1; i>index; i--){
            if(a[i] > a[index]){
                  swap(a[i], a[index]);
                  break;
            }
      }
      reverse(a+index+1, a+n);
    
      for(int i=0; i<n; i++){
            cout << a[i] << " ";
      }
}