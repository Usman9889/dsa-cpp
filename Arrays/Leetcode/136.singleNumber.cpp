



// code
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        int num = a[i];
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] == num) {
                cnt++;
            }
        }
        if(cnt == 1){
                cout << num;
                break;
            }
    }

}