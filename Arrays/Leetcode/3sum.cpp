#include <bits/stdc++.h>
using namespace std;

// Brute Force(nested loops)
// Time complexity: O(N^3 * log(no. of unique triplets))
// Here, we are mainly using 3 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.
// Space complexity: O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
vector<vector<int>>BruteForce(vector<int>& arr, int n){
    //set to store unique triplets
    set<vector<int>>st;

    //First loop for first element
    for(int i =0; i<n; i++){
      //Second loop for second element
        for(int j = i+1; j<n; j++){
            //Third loop for third element
            for(int k=j+1; k<n; k++){
                  //If sum of three elements is 0
                if(arr[i] + arr[j] + arr[k] == 0){
                  // Store sorted triplet to avoid duplicates
                    vector<int> temp = { arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
// Better Approach(hashmap)
// time complexity:
// space complexity:
vector<vector<int>> Better(vector<int>& arr, int n){
    set<vector<int>>ans;
    
    for(int i=0; i<n; i++){
        set<int>st;
        for(int j = i + 1; j<n; j++){
            int third = -(arr[i] + arr[j]);
            
            if(st.find(third) != st.end()){
                vector<int>temp = {arr[i] , arr[j], third};
                sort(temp.begin(), temp.end());
                ans.insert(temp);
            }
            st.insert(arr[j]);
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end()); 
}

// Optimal Approach(2 pointers)
// Time complexity:  O(NlogN)+O(N^2)
// Space complexity:O(no. of quadruplets), This space is only used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
vector<vector<int>> Optimal(vector<int>& arr, int n){
     sort(arr.begin(), arr.end());
     
     vector<vector<int>> ans;
     
     for(int i=0; i<n; i++){
         // Skip duplicates for first element
         if(i > 0 && arr[i] == arr[ i-1]) continue;
         
         int left = i+1, right = n-1;
         
         while(left < right){
             int sum = arr[i] + arr[left] + arr[right];
             
             if(sum == 0){
                 ans.push_back({arr[i], arr[left], arr[right]});
                 left++;
                 right--;
                 // Skip duplicates for left
                 while(left < right && arr[left] == arr[left - 1]) left++;
                 while(left < right && arr[right] == arr[right + 1]) right++;
             }
             else if( sum < 0) left++;
             else right--;
         }
     }
     return ans;
}
int main() {
	vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = BruteForce(arr, n);
    vector<vector<int>> ans2 = Better(arr, n);
    vector<vector<int>> ans3 = Optimal(arr, n);
    for(auto &it : ans){
        for(auto &x : it){
            cout << x << " ";
        }
        cout << endl;
    }
}
