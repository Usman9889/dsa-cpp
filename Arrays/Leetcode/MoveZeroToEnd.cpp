// Brute Force Approach: The extremely naive solution, we can think of, involves the use of an extra array. 
// Time Complexity: O(N), we can move all zeroes to end in linear time.
// Space Complexity: O(N), additional space used for temporary array.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    std::vector < int > temp;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);

        }
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
// Optimal Approach: We can optimize the approach using 2 pointers i.e. i and j. The pointer j will point to the first 0 in the array and i will point to the next index.
// Time Complexity: O(N), we can move all zeroes to end in linear time.
// Space Complexity: O(1), constant additional space is used.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++) {
        if (a[i] != 0) {
            swap(a[i], a[j]);
            j++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}