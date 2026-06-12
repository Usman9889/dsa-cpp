#include <bits/stdc++.h>

using namespace std;

long long nCr(int n) {
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        cnt *= i;
    }
    return cnt;
}

int main() {
    long long n, r;
    cin >> n >> r;
    long long nFac = nCr(n);
    long long rFac = nCr(r);
    long long nrFac = nCr(n - r);
    cout << nFac / (rFac * nrFac);
}