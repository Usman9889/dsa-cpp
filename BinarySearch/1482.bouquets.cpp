#include <bits/stdc++.h>
using namespace std;

//Brute Force
int minDaysBrute(vector<int>& bloomDay, int m, int k) {
      int n = bloomDay.size();

    // Total flowers required
    if (n < m * k) {
        return -1;
    }

    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

    // Try every possible day
    for (int day = minDay; day <= maxDay; day++) {

        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {

            if (bloom <= day) {
                flowers++;

                // k consecutive flowers form one bouquet
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }

            } else {
                // Break in consecutive flowers
                flowers = 0;
            }
        }

        // We need m bouquets
        if (bouquets >= m) {
            return day;
        }
    }

    return -1;
}
//Optimal Approach
bool canMakeBouquets(vector<int>& bloomDay, int day, int m, int k){
    int flowers = 0;
    int bouquets = 0;
    
    for(int bloom : bloomDay){
        if(bloom <= day){
            flowers++;
            
            if(flowers == k){
                bouquets++;
                flowers = 0;
            }
        }else{
            flowers = 0;
        }
    }
    return bouquets >= m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
    
    int n = (int)bloomDay.size();
    
    if (n < m * k) {
        return -1;
    }

    int minDay = *min_element(bloomDay.begin(), bloomDay.end());
    int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
    
    int low = minDay, high = maxDay;
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low)/2;
        
        if(canMakeBouquets(bloomDay, mid, m, k)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}
int main() {

    vector<int> bloomDay = {7, 7, 7, 7, 12, 7, 7};

    int m = 2; // number of bouquets
    int k = 3; // flowers per bouquet
    //brute force
    cout << "Answer from brute force approach: "<<minDaysBrute(bloomDay, m, k) << endl;
    
    //optimal
    cout <<"Answer from optimal force approach: "<< minDays(bloomDay, m, k) << endl;

}