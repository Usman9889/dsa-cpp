#include <bits/stdc++.h>

using namespace std;

int smallestDivisor(vector < int > & nums, int threshold) {
    int maxVal = * max_element(nums.begin(), nums.end());

    for (int divisor = 1; divisor <= maxVal; divisor++) {
        int total = 0;
        
        for(int num : nums){
            total += (num + divisor -1)/divisor;
            
            if(total > threshold) break;
        }
         if(total <= threshold){
             return divisor;
         }
    }
   return maxVal;
}
//Optimal Approach
int smallestDivisorOptimal(vector<int> &nums, int threshold){
    int low = 1;
    int high = 0;
    long long totalSum = 0;
    
    for(int num : nums){
        totalSum += num;
        high = max(high, num);
    }
    
    //If threshold >= total sum, divisor 1 is sufficient.
    if (threshold >= totalSum) {
        return 1;
    }
    
    //If threshold equals array length, each number must contribute requiring max element.
    if (threshold == static_cast<int>(nums.size())) {
        return high;
    }
    
    while(low <= high){
        
        //mid is the divisor being tested in this round.
        int mid = low + (high - low) / 2;
        int total = 0;
        
        for(int num : nums){
            total += (num + mid - 1)/ mid;
            
            if(total > threshold) break;
        }
        if(total <= threshold){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    cout << smallestDivisor(nums, threshold) << endl;
    cout << smallestDivisorOptimal(nums, threshold) << endl;
    

    return 0;
}