// Approaches:
// 1. Brute Force:
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;

    int maxLen = 0;
    // starting index
    for (int i = 0; i < n; i++) {
        int sum = 0;
    // ending index
        for (int j = i; j < n; j++) {
            sum += a[j];

            if (sum == k) {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }
    cout << maxLen;
}