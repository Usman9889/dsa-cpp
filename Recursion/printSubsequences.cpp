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