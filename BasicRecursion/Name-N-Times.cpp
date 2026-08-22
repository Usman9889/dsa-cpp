#include<iostream>
using namespace std;

void printname(int i, int n){
      if(i > n)
      return;
      cout << "Usman" << endl;
      printname(i + 1, n);
}
int main(){
      int n;
      cin >> n;
      printname(1, n);
}
//Sum of natural numbers using recursion
#include <iostream>
using namespace std;

int sum(int  n){
    
    // base condition
    if (n == 1)
     return  1 ;
     
    return n + sum(n - 1); 
}

int main() {
    int n = 5 ;
    cout <<  sum(n); 
    return 0;
}