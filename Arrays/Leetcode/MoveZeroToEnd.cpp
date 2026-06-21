#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    std::vector < int > temp;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);

        }
    }
    int nz = temp.size();
    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}