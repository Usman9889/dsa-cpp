//Brute Force:
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& a, int n){
      
      for(int i=0; i<a.size(); i++){
            if(a[i] == n){
                  return true;
            }
      }
      return false;
}
int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      
      if(a.size() == 0){
            cout << 0 << endl;
            return 0;
      }
      int longest = 1;
      for(int i=0; i<n; i++){
            int x = a[i];
            int cnt = 1;
            while(linearSearch(a, x + 1)){
                  x = x + 1;
                  cnt += 1;
            }
            longest = max(longest, cnt);
      }
      cout << longest << endl;
}

//Better Approach:
#include <bits/stdc++.h>
using namespace std;
int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      
      if(a.size() == 0){
            return 0;
      }
      sort(a.begin(), a.end());
      int longest = 1;
      int cnt = 0;
      int lastSmaller = INT_MIN;

      for(int i=0; i<n; i++){
            if(a[i] - 1 == lastSmaller){
                  cnt += 1;
                  lastSmaller = a[i];
            }
            else if(a[i] != lastSmaller){
                  cnt = 1;
                  lastSmaller = a[i];
            }
            longest = max(longest, cnt);
      }
      cout << longest << endl;              
}


//Optimal Approach:
#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      vector<int> a(n);
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      
      if(a.size() == 0){
            cout << 0 << endl;
            return 0;
      }
      unordered_set<int> s;
      for(int i=0; i<n; i++){
            s.insert(a[i]);
      }
      
      int longest = 1;
      for(int i=0; i<n; i++){
            if(s.find(a[i] - 1) == s.end()){
                  int x = a[i];
                  int cnt = 1;
                  while(s.find(x + 1) != s.end()){
                        x = x + 1;
                        cnt += 1;
                  }
                  longest = max(longest, cnt);
            }
      }
      cout << longest << endl;
}