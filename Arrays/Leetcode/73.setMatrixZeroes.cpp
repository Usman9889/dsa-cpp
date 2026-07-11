//Brute Force Approach:

#include <bits/stdc++.h>
using namespace std;
int main(){
      int n, m;
      cin >> n >> m;
      int arr[n][m];
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cin >> arr[i][j];
            }
      }
       // Mark all elements in this row as -1 (except existing zeros)
      void markRow(int row){
            for(int j=0; j<m; j++){
                  if(arr[row][j] != 0){
                        arr[row][j] = -1;
                  }
            }
      }
       // Mark all elements in this column as -1 (except existing zeros)
      void markCol(int col){
            for(int i=0; i<n; i++){
                  if(arr[i][col] != 0){
                        arr[i][col] = -1;
                  }
            }
      }

      // Traverse each cell of the matrix
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  // If current cell is zero
                  if(arr[i][j] == 0){
                           markRow(i);
                           markCol(j);
                  }
            }
      }
      //replace all -1 markers with 0
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  if(arr[i][j] == -1){
                        arr[i][j] = 0;
                  }
            }
      }
}