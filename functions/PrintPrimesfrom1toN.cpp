#include <bits/stdc++.h>

using namespace std;


bool prime(int n) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cnt++;
        }
    }
    return (cnt == 2);

}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (prime(i)) {
            cout << i<< " ";
        }
    }
}