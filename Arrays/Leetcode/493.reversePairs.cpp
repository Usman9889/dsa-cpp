#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high) {

    int left = low;
    int right = mid + 1;

    vector<int> temp;

    while(left <= mid && right <= high) {

        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to arr
    for(int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

int countPairs(vector<int> &arr, int low, int mid, int high) {

    int cnt = 0;
    int right = mid + 1;

    for(int i = low; i <= mid; i++) {

        while(right <= high && 
              (long long)arr[i] > 2LL * arr[right]) {
            right++;
        }

        cnt += right - (mid + 1);
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high) {

    int cnt = 0;

    if(low >= high)
        return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);

    cnt += mergeSort(arr, mid + 1, high);

    // Count reverse pairs
    cnt += countPairs(arr, low, mid, high);

    // Merge sorted halves
    merge(arr, low, mid, high);

    return cnt;
}

int main() {

    vector<int> arr = {12, 11, 13, 5, 6, 7};

    int ans = mergeSort(arr, 0, arr.size() - 1);

    cout << "Reverse pairs: " << ans << endl;

    return 0;
}