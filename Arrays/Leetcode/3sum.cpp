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


int main() {
	vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = BruteForce(arr, n);
    vector<vector<int>> ans2 = Better(arr, n);
   
    for(auto &it : ans){
        for(auto &x : it){
            cout << x << " ";
        }
        cout << endl;
    }
}
