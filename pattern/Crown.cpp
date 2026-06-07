#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        //for i stars
        for (int j = 1; j <= i; j++) 
        {
            cout << "*";
        }

        //for 2n-2i stars
        for (int j = 1; j <= 2 * (n - i); j++) 
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