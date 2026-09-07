
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
// Better Approach
// Time complexity: O(n*m)
// Space complexity: O(n+m)
vector<vector<int>> setZeroesBetter(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);

    // Mark rows and columns that contain zeros
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    // Set elements to zero based on marked rows and columns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}
// Optimal Approach
// Time complexity: O(n*m)
// Space complexity: O(1)
vector<vector<int>> setZeroesOptimal(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
      bool firstRowHasZero = false;
      bool firstColHasZero = false;
      // Check if first row has a zero
      for (int j = 0; j < m; j++) {
            if (matrix[0][j] == 0) {
                  firstRowHasZero = true;
                  break;
            }
      }
      // Check if first column has a zero
      for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                  firstColHasZero = true;
                  break;
            }
      }
      // Mark rows and columns that contain zeros
      for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                  if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                  }
            }
      }
      // Set elements to zero based on marked rows and columns
      for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                  if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                  }
            }
      }
      // Set first row to zero if needed
      if (firstRowHasZero) {
            for (int j = 0; j < m; j++) {
                  matrix[0][j] = 0;
            }
      }
      // Set first column to zero if needed
      if (firstColHasZero) {
            for (int i = 0; i < n; i++) {
                  matrix[i][0] = 0;
            }
      }
      return matrix;    
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    
//     setZeroesBruteForce(matrix);
//     setZeroesBetter(matrix);
      setZeroesOptimal(matrix);
    // Print final matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}