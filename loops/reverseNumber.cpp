#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string N;
    cin >> N;
 
    for (int i = N.length() - 1; i >= 0; i--) {
        cout << N[i];
    }
 
    cout << endl;
;
}