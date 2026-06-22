#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n - 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= n; i++) {
        xor1 ^= i;
    }

    for (int i = 0; i < n - 1; i++) {
        xor2 ^= a[i];
    }

    int ans = xor1 ^ xor2;

    cout << ans;

    return 0;
}

// class Solution {
// public:
//     int missingNumber(vector<int>& nums) {
//         int n = nums.size() ;
//         int xor1 = 0, xor2 = 0;

//         for(int i = 0; i < n; i++){
//             xor2 ^= nums[i];
//             xor1 ^= i ;
//         }
//         xor1 ^= n;
//         return xor1 ^ xor2;
//     }
// };