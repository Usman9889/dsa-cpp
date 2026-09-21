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
int main() {

    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    vector < vector < int >> answer = fourSumBrute(nums, target);

    for (const auto & quadruplet: answer) {
        for (int value: quadruplet) {
            cout << value << " ";
        }
        cout << endl;
    }

}