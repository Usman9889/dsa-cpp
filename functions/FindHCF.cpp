#include <bits/stdc++.h>

using namespace std;

int HCF(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = HCF(a, b);
    cout << ans;

}