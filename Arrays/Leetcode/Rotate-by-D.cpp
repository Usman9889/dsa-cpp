#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int d;
    cin >> d;
    int temp[d];

    for (int i = 0; i < d; i++) {
        temp[i] = a[i];

    }

    for (int i = d; i < n; i++) {
        a[i - d] = a[i];
    }
    int i = 0;
    for (int j = n - d; j < n; j++) {
        a[j] = temp[i];
        i++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}