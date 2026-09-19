#include <bits/stdc++.h>
using namespace std;

// To find the element at the coordinates (R,C) where R is the row number and C is the Column number.
// Function to compute binomial coefficient (nCr)
//Time Complexity: O(r)
// Space Complexity: O(1)
long long findPascalElement(int r, int c) {
        // Element is C(r-1, c-1) 
        int n = r - 1;
        int k = c - 1;
        int val = 1;
        for(int i = 0; i < k; i++){
            val = val * (n-i)/(i+1);
        }
        return val;
    }
//To print the Nth row of the pascal triangle
vector<long long> printNthRow(int n){
    vector<long long> row;
    long long val = 1;
    row.push_back(val);

    for(int i=1; i<n; i++){
        val = val * (n-i)/i;
        row.push_back(val);
    }
    return row;
}
int main(){
    int r = 5, c = 3;
    int ans = findPascalElement(r,c);
    cout << ans;

    // To print the Nth row of the pascal triangle
    int n = 5;
    vector<long long> result = printNthRow(n);
    for(auto x : result){
        cout << x <<" ";
    }
}