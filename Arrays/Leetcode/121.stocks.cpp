#include<iostream>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      int minPrice = arr[0];
      int maxProfit = 0;

      for(int i=1; i<n; i++){
            int cost = arr[i] - minPrice;
            maxProfit = max(maxProfit, cost);
            minPrice = min(minPrice, arr[i]);
      }
      cout << maxProfit << endl;
}