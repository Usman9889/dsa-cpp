#include <bits/stdc++.h>

using namespace std;


void prime(int n) {
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (n % i == 0) {
            cnt++;
        }
    }
    if (cnt == 2) {
        cout << "Prime" << endl;
    }
    else {
        cout << "Not Prime";
    }
}

int main() {
    int n;
    cin >> n;
    prime(n);

}