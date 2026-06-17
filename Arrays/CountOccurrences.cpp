#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i <= n - 1; i++) {
        cin >> a[i];

    }
    // long long ans = a[0];
    int count = 0;
    for (int i = 0; i <= n - 1; i++) {
        if (a[i] == m) {
            count++;
        }
    }
    cout << count << endl;

}