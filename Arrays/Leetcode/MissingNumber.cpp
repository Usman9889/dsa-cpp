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