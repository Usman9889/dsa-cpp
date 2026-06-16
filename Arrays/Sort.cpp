#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];
    }

    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            c0++;
        }
        else {
            c1++;
        }
    }
    for (int i = 1; i <= c0; i++) {
        cout << "0 ";
    }
    for (int i = 1; i <= c1; i++) {
        cout << "1 "  ;
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}