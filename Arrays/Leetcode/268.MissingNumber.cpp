// Approaches:
// 1. Brute Force: Linear Search for Missing Number - O(n^2) Time and O(1) Space
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n - 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << i;
        }
    }
}
// 2. [Better Approach] Using Hashing - O(n) Time and O(n) Space
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n - 1];
      for(int i = 0; i < n - 1; i++){
            cin >> a[i];
      }
      vector<int> hash(n + 1, 0);

      for(int i = 0; i < n - 1; i++){
            hash[a[i]]++;
      }

      for(int i = 1; i <= n; i++){
            if(hash[i] == 0){
                  cout << i;
                  break;
            }
      }
}
// 3.Optimal: Using Sum of n terms Formula - O(n) Time and O(1) Space
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n - 1];
      for(int i = 0; i < n - 1; i++){
            cin >> a[i];
      }
      //calculate sum of array of elements
      int sum = 0;
      for(int i = 0; i < n-1; i++){
            sum += a[i];
      }
      //calculate expected sum from 1 to n
      long long expSum = n * (n + 1) /2;

      cout << expSum - sum;
}

// Optimal: Using XOR Operation - O(n) Time and O(1) Space
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