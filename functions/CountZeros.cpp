#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;

    // Special case
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }

    int countZero = 0;
    while (N > 0) {
        if (N % 10 == 0) {
            countZero++;
        }
        N /= 10;
    }

    cout << countZero << endl;
    return 0;
}
