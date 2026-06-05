#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = n; i >= 1; i--) {
        //for i stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        //for 2n-2i stars
        for (int j = 1; j <= 2 * (n - i) + 1; j++)
        {
            cout << " ";
        }

        //for i stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 2; i <= n; i++) {
        //for i stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        //for 2n-2i stars
        for (int j = 1; j <= 2 * (n - i) + 1; j++)
        {
            cout << " ";
        }

        //for i stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }


}