#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    for (int i = 1; i <= n; i++) {
        int start;
        if (i % 2 == 1) {
            start = 0;
        }
        else {
            start = 1;
        }
        for (int j = 1; j <= i; j++) {
            cout << start;
            start = 1 - start;
 
        }
        cout << endl;
    }
 
}