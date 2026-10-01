#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};

    int m = 2; // number of bouquets
    int k = 3; // flowers per bouquet

    int n = bloomDay.size();

    // Total flowers required
    if (n < m * k) {
        cout << -1 << endl;
        return 0;
    }

    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

    // Try every possible day
    for (int day = minDay; day <= maxDay; day++) {

        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {

            if (bloom <= day) {
                flowers++;

                // k consecutive flowers form one bouquet
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }

            } else {
                // Break in consecutive flowers
                flowers = 0;
            }
        }

        // We need m bouquets
        if (bouquets >= m) {
            cout << day << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}