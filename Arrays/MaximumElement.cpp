#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];

    }
    long long ans = a[0], location = 1;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] > ans) {
            ans = a[i];
            location = i + 1;
        }
    }
    cout << ans << " " << location << endl;

}