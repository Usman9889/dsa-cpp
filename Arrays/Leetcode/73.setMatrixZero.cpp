
#include <bits/stdc++.h>
using namespace std;
//Brute Force Approach
// Time complexity: O(n*m*(n+m))
// Space complexity: O(1)
vector<vector<int>> setZeroesBruteForce(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();

      auto markRow = [&](int i){
            for(int j=0; j<m; j++){
                  if(matrix[i][j] !=0 ){
                        matrix[i][j] = -1;
                  }
            }
      };
      auto markCol = [&](int j){
            for(int i=0; i<n; i++){
                  if(matrix[i][j] !=0 ){
                        matrix[i][j] = -1;
                  }
            }
      };
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  if(matrix[i][j] == 0){
                        markRow(i);
                        markCol(j);
                  }
            }
      }
      // Convert all marked cells into 0
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
    return matrix;
}
int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
    // Call function to modify matrix
    setZeroesBruteForce(matrix);
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}