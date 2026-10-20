
#include <bits/stdc++.h>
using namespace std;

int countSubsequences(int index, vector<int>& arr, int sum, int k) {
    // Base case
    if (index == arr.size()) {
        if (sum == k) {
            return 1;
        }
        return 0;
    }

    // Pick the current element
    int pick = countSubsequences(
        index + 1, arr, sum + arr[index], k
    );

    // Do not pick the current element
    int notPick = countSubsequences(
        index + 1, arr, sum, k
    );

    return pick + notPick;
}

int main() {
    vector<int> arr = {3, 1, 2};
    int k = 3;

    cout << countSubsequences(0, arr, 0, k);

    return 0;
}
