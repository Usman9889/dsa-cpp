//Approach:
// Brute Force:
#include<iostream>
#include<vector>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      vector<int> pos;
      vector<int> neg;

      for(int i=0; i<n; i++){
            if(arr[i] > 0){
                  pos.push_back(arr[i]);
            } else{
                  neg.push_back(arr[i]);
            }
      }

      for (int i=0; i<n/2; i++){
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
      }

      for(int i=0; i<n; i++){
            cout << arr[i] << " ";
      }

}

// 2. Optimal:
#include<iostream>
#include<vector>
using namespace std;

int main(){
      int n;
      cin >> n;
      int arr[n];
      for(int i=0; i<n; i++){
            cin >> arr[i];
      }
      vector<int>ans(n, 0);
      int posIndex = 0, negIndex = 1;
      for(int i=0; i<n; i++){
            if(arr[i] < 0){
                  ans[negIndex] = arr[i];
                  negIndex += 2;
            }else{
                  ans[posIndex] = arr[i];
                  posIndex += 2;
            }
      }

      for(int i=0; i<n; i++){
            cout << ans[i] << " ";
      }

}
