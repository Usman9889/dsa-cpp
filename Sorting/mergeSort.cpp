#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
      vector<int> temp;
      int left = low, right = mid + 1;
            while(left <= mid && right <= high){
                  if(arr[left] <= arr[right]){
                        temp.push_back(arr[left]);
                        left++;
                  }else{
                        temp.push_back(arr[right]);
                        right++;
                  }
            }
            while(left <= mid){
                  temp.push_back(arr[left]);
                  left++;
            }
            while(right <= high){
                  temp.push_back(arr[right]);
                  right++;
            }
            for(int i = low; i <= high; i++){
                  arr[i] = temp[i - low];
            }
      
      //printing sorted array
      if(low == 0 && high == arr.size() - 1){
            cout << "Sorted array: ";
            for(int i = 0; i < arr.size(); i++){
                  cout << arr[i] << " ";
            }
            cout << endl;
      }
      
}

void mergeSort(vector<int> &arr, int low, int high){
      if(low < high){
            int mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
      }
}
int main(){
      vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
      int left = 0, right = arr.size() - 1;
      mergeSort(arr, left, right);
}