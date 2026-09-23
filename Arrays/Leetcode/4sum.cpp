#include <bits/stdc++.h>

using namespace std;

vector < vector < int >> fourSumBrute(vector < int > & arr, int target) {

    int n = arr.size();
    set < vector < int >> st;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    long long Sum = (long long) arr[i] + arr[j] + arr[k] + arr[l];
                    if (Sum == target) {
                        vector < int > temp = {
                            arr[i],
                            arr[j],
                            arr[k],
                            arr[l]
                        };
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    return vector<vector<int>>(st.begin(), st.end());

}

vector < vector < int >> fourSumBetter(vector < int > & arr, int target) {
    int n = arr.size();
    set < vector < int >> ans;

    for (int i = 0; i < n; i++) {
        set < int > st;
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                long long required = (long long) target - (arr[i] + arr[j] + arr[k]);
                if (st.count(required)) {
                    vector < int > temp = {
                        arr[i],
                        arr[j],
                        arr[k],
                        (int) required
                    };
                    sort(temp.begin(), temp.end());
                    ans.insert(temp);
                }
                st.insert(arr[k]);
            }
        }
    }
    return vector < vector < int >> (ans.begin(), ans.end());
}
vector < vector < int >> fourSumOptimal(vector < int > & arr, int target) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector < vector < int >> ans;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){
            int left = j + 1, right = n - 1;
            while(left < right){
                long long Sum = arr[i] + arr[j] + arr[left] + arr[right];
                if(Sum == target){
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                    left ++;
                    right --;
                    while(left < right && arr[left] == arr[left - 1]) left ++;
                    while(left < right && arr[right] == arr[right + 1]) right --;
                }
                else if(Sum < target) left ++;
                else right --;
            }
            
        }
    }
        return ans;
}
int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // vector < vector < int >> brute = fourSumBrute(nums, target);
    // vector < vector < int >> better = fourSumBetter(nums, target);
    vector < vector < int >> optimal = fourSumOptimal(nums, target);
    
    for (const auto & quadruplet: optimal) {
        for (int value: quadruplet) {
            cout << value << " ";
        }
        cout << endl;
    }

}