#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];

    }
    // long long ans = a[0];
    bool sort = false;
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] >= a[i - 1]) {
           
        }
        else {
            sort = true;
        }
    }
    if (sort) {
        cout << " No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

}