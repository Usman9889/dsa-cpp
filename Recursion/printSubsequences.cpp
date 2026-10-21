#include<bits/stdc++.h>
using namespace std;
void printSubsequences(int index, vector<int> arr, vector<int> current ){
      //base case
      if(index == arr.size()){
            for(int it : current){
                  cout << it << " ";
            }
            cout << endl;
            return;
      }
      //Pick the current element
      current.push_back(arr[index]);
      printSubsequences(index + 1, arr, current);

      //Backtrack: remove the current element
      current.pop_back();

      //Do not pick the current element
      printSubsequences(index + 1, arr, current);
}
int main(){
      vector<int> arr = {3, 1, 2};
      vector<int> current;
      
      printSubsequences(0,arr, current);
      return 0;
}

/*To print all subsequences whose sum equals k, use the same pick / not-pick recursion, but print a subsequence only when its sum equals k.

#include <bits/stdc++.h>
using namespace std;

void printSubsequences(int index, vector<int>& arr,
                       vector<int>& current, int sum, int k) {
    // Base case
    if (index == arr.size()) {
        if (sum == k) {
            for (int x : current) {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }

    // Pick the current element
    current.push_back(arr[index]);
    printSubsequences(index + 1, arr, current,
                      sum + arr[index], k);

    // Backtrack
    current.pop_back();

    // Do not pick the current element
    printSubsequences(index + 1, arr, current, sum, k);
}

int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> current;
    int k = 3;

    printSubsequences(0, arr, current, 0, k);

    return 0;
}

*/