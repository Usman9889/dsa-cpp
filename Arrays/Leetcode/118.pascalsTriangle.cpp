#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------
// 1. Find element at row R, column C
// ---------------------------------------------------------
// Pascal Triangle uses 1-based indexing:
//
// Element(R, C) = C(R-1, C-1)
//
// Time Complexity: O(C)
// Space Complexity: O(1)

long long findPascalElement(int r, int c) {

    int n = r - 1;
    int k = c - 1;

    long long val = 1;

    for(int i = 0; i < k; i++) {
        val = val * (n - i) / (i + 1);
    }

    return val;
}


// ---------------------------------------------------------
// 2. Print Nth row of Pascal Triangle
// ---------------------------------------------------------
// Example:
// n = 5
//
// 1 4 6 4 1
//
// Time Complexity: O(N)
// Space Complexity: O(N)

vector<long long> printNthRow(int n) {

    vector<long long> row;

    long long val = 1;

    row.push_back(val);

    for(int i = 1; i < n; i++) {

        val = val * (n - i) / i;

        row.push_back(val);
    }

    return row;
}


// ---------------------------------------------------------
// 3. Print entire Pascal Triangle
// ---------------------------------------------------------
// Time Complexity: O(N^2)
// Space Complexity: O(N)
//   -> because we store only the current row

void pascalsTriangle(int n) {

    for(int i = 1; i <= n; i++) {

        vector<long long> row = printNthRow(i);

        for(auto x : row) {
            cout << x << " ";
        }

        cout << endl;
    }
}


int main() {

    // -----------------------------------------------------
    // Find element at row R, column C
    // -----------------------------------------------------

    int r = 5;
    int c = 3;

    long long ans = findPascalElement(r, c);

    cout << "Element at row " << r
         << ", column " << c << " = "
         << ans << endl;


    // -----------------------------------------------------
    // Print Nth row - Brute Force
    // -----------------------------------------------------

    int n = 5;

    cout << "Nth row using brute force: ";

    // Each element requires O(n)
    // n elements -> O(n^2)

    for(int c = 1; c <= n; c++) {

        cout << findPascalElement(n, c) << " ";
    }

    cout << endl;


    // -----------------------------------------------------
    // Print Nth row - Optimal
    // -----------------------------------------------------

    cout << "Nth row using optimal approach: ";

    vector<long long> result = printNthRow(n);

    for(auto x : result) {

        cout << x << " ";
    }

    cout << endl;


    // -----------------------------------------------------
    // Print entire Pascal Triangle
    // -----------------------------------------------------

    cout << "Pascal Triangle:" << endl;

    pascalsTriangle(n);


    return 0;
}