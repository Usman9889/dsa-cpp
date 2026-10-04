#include<bits/stdc++.h>
using namespace std;
int shipWithinDays(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(), weights.end());
      int high = accumulate(weights.begin(), weights.end(), 0);
      
      for(int capacity = low; capacity <= high; capacity++){
            int daysRequired = 1;
            int currentCapacity = 0;
            for(int weight : weights){
                  currentCapacity += weight;
                  if(currentCapacity > capacity){
                        daysRequired += 1;
                        currentCapacity = weight;
                  }
            }
            if(daysRequired <= days) return capacity;
      }
      return 0;
}
int shipWithinDaysOptimal(vector<int>& weights, int days) {
      int low = *max_element(weights.begin(), weights.end());
      int high = accumulate(weights.begin(), weights.end(), 0);
      while(low < high){
            int mid = low + (high - low)/2;
            int daysRequired = 1;
            int currentCapacity = 0;
            for(int weight : weights){
                 if(currentCapacity + weight <= mid){
                       
                       currentCapacity += weight;
                 }else{
                        daysRequired += 1;
                       currentCapacity = weight;
                 }
            }
            if(daysRequired <= days) high = mid - 1;
            else low = mid + 1;
      }
      return low;
}
int main(){
      vector<int> weights = {1,2,3,4,5,6,7,8,9,10};
      int days = 5;
      cout << shipWithinDays(weights, days) << endl;
      cout << shipWithinDaysOptimal(weights, days) << endl;
}