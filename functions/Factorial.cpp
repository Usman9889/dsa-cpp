#include <bits/stdc++.h>

using namespace std;


long long prime(int n) {
    long long cnt = 1;
    for (int i = 1; i <= n; i++) {
        cnt *= i;
    }
    return cnt;
}

int main() {
    long long n;
    cin >> n;
    long long ans = prime(n);
    cout << ans;
}