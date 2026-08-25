//Brute Force Approach
//Time complexity: O(n)
//Space complexity: O(n)
#include <bits/stdc++.h>
using namespace std;
int main(){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
                cin >> arr[i];
        }
        set<int> st;
        int index = 0;
        for(int i=0; i<n; i++){
                if(st.find(arr[i]) == st.end()){
                        st.insert(arr[i]);
                        arr[index++] = arr[i];
                }
        }
        for(int i=0; i<index; i++){
                cout << arr[i] << " ";
        }
        cout << endl;
}


class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
         if (nums.empty()) return 0;
        int i =0;
        for (int j = 1; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};