// Approaches:
// 1. Brute Force:
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target;
    cin >> target;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            if(a[i] + a[j] == target){
                cout << i << " " << j << endl;
                return 0;        // Exit after finding the answer
            }
        }
    }

    return 0;
}

// 2. Better (hashing)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int target;
    cin >> target;

    map<int, int> mpp;

    for(int i=0; i<n; i++){
      int num = a[i];
      int moreElement = target - num;
      if(mpp.find(moreElement) != mpp.end()){
            cout << mpp[moreElement] << "," << i;
      }
      mpp[num] = i;
    }
    
}

// 3.Optimal Approach(sorted array)
// If array is not sorted: we will first sort the array and then try to choose the numbers in a greedy way.
// We will keep a left pointer at the first index and a right pointer at the last index. Now until left < right, we will check the sum of arr[left] and arr[right]. Now if the sum < target, we need bigger numbers and so we will increment the left pointer. But if sum > target, we need to consider lesser numbers and so we will decrement the right pointer.

#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target)
            return {left, right};

        else if (sum < target)
            left++;

        else
            right--;
    }

    return {-1, -1};
}

int main() {
    vector<int> arr = {2, 4, 7, 11, 15};
    int target = 18;

    auto ans = twoSum(arr, target);

    cout << ans.first << " " << ans.second;
}