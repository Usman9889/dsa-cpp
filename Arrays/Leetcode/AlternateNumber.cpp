//we cant,t use optimal solution because the optimal solution was lying on the fact that the number of positive and negative numbers are equal(2149 arrayBysign). But in this case we have to consider the case when the number of positive and negative numbers are or not equal. So we will use the first approach which is a brute force approach.

#include <bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin >> n;
      int a[n];
      for(int i=0; i<n; i++){
            cin >> a[i];
      }
      vector<int> pos, neg;
      for(int i=0; i<n; i++){
            if(a[i] < 0){
                  neg.push_back(a[i]);
            }else{
                  pos.push_back(a[i]);
            }
      }
      if(pos.size() > neg.size()){
            for(int i=0; i<neg.size(); i++){
                  a[i*2] = pos[i];
                  a[i*2 + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for(int i=neg.size(); i<pos.size(); i++){
                  a[index] = pos[i];
                  index++;
            }
      }else{
            for(int i=0; i<pos.size(); i++){
                  a[i*2] = pos[i];
                  a[i*2 + 1] = neg[i];
            }
            int index = pos.size() * 2;
            for(int i=pos.size(); i<neg.size(); i++){
                  a[index] = neg[i];
                  index++;
            }
      }
      for(int i=0; i<n; i++){
            cout << a[i] << " ";
      }        
      
}