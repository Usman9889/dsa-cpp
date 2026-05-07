#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long factorial = 1;
    for (int i = n; i > 0; i--) {
        factorial = factorial *i;
    }
    cout << factorial;
}