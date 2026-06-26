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

// 2. Optimal:

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
    // To store the maximum length of the subarray
    int maxLen = 0;
    
    // Pointers to mark the start and end of window
    int left = 0, right = 0;
    
    // To store the sum of elements in the window
    int sum = a[0];
    
// Traverse all the elements
    while (right < n) {
        
        // If the sum exceeds K, shrink the window        
        while (left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        
      // store the maximum length
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n) {
            sum += a[right];
        }
    }
    cout << maxLen;

}