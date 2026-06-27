// Approaches:(For Brute Force use any sorting algorithm)
// 2. Better
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int zero = 0, one = 0, two = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) zero++;
        else if (a[i] == 1) one++;
        else two++;
    }

    for (int i = 0; i < zero; i++) {
        a[i] = 0;
    }
    for (int i = zero; i < zero + one; i++) {
        a[i] = 1;
    }
    for (int i = zero + one; i < n; i++) {
        a[i] = 2;
    }
    for (int x: a)
        cout << x << " ";

}
// 3.Optimal
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0) {
            swap(a[mid], a[low]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else {
            swap(a[mid], a[high]);
            high--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

}