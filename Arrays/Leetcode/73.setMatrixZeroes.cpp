#include <bits/stdc++.h>
using namespace std;

// Mark all elements in the given row as -1 (except existing zeros)
void markRow(vector<vector<int>> &arr, int row, int m) {
    for (int j = 0; j < m; j++) {
        if (arr[row][j] != 0) {
            arr[row][j] = -1;
        }
    }
}

// Mark all elements in the given column as -1 (except existing zeros)
void markCol(vector<vector<int>> &arr, int col, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i][col] != 0) {
            arr[i][col] = -1;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // Traverse each cell
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    // Replace all -1 with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }

    // Print the modified matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

//Better Approach: Using extra row and first column as markers

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
      int col[m] = {0};
      int row[n] = {0};
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  if(arr[i][j] == 0){
                        row[i] = 1;
                        col[j] = 1;
                  }
            }
      }
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  if(row[i] == 1 || col[j] == 1){
                        arr[i][j] = 0;
                  }
            }
      }
      for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                  cout << arr[i][j] << " ";
            }
            cout << endl;
      }
}