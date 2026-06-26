// Approaches:
// 1. Brute Force:
#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int target;
    cin >> target;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){

            if(a[i] + a[j] == target){
                cout << i << " " << j << endl;
                return 0;        // Exit after finding the answer
            }
        }
    }

    return 0;
}

// 2. Better (hashing)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int target;
    cin >> target;

    map<int, int> mpp;

    for(int i=0; i<n; i++){
      int num = a[i];
      int moreElement = target - num;
      if(mpp.find(moreElement) != mpp.end()){
            cout << mpp[moreElement] << "," << i;
      }
      mpp[num] = i;
    }
    
}