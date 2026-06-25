/*
Problem: Find the number that appears onc
Difficulty: Easy
Company Tags: Amazon, Microsoft, Google, Flipkart, Atlassian, Adobe, Walmart Global Tech, etc.
Problem Link: https://leetcode.com/problems/single-number/description/
*/

// Approaches:
// 1. Brute Force: 
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 // Loop through every element
    for (int i = 0; i < n; i++) {
        int num = a[i]; // current element to check
        int cnt = 0;

// Count occurrences of this element
        for (int j = 0; j < n; j++) {
            if (a[j] == num) {
                cnt++;
            }
        }
        if(cnt == 1){
                cout << num;
                break;
            }
    }

}
// Time Complexity: O(N*N), since nested for loops are used
// Space Complexity: O(1). No extra space used
*/

// 2. Better: (Hashing)
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
// Step 1: Find the maximum value in the array
    int maxi = a[0];
    for (int i = 0; i < n; i++) {
        maxi = max(a[i], maxi);
    }
// Step 2: Declare and initialize hash array of size maxi+1
    vector < int > hash(maxi + 1, 0);

// Step 3: Count the frequency of each number
    for (int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
// Step 4: Find the element that occurs exactly once
    for (int i = 0; i < n; i++) {
        if(hash[a[i]] == 1) {
            cout << a[i];
        }
    }

}
// Time Complexity: O(N)+O(N)+O(N), where N = size of the array. One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.

// Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
*/

// 3. Optimal: (XOR)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr ^= a[i];
    }
    cout << xorr;
}

// Time Complexity: O(N). Where N is the size of the array
// Space Complexity: O(1). No extra space used