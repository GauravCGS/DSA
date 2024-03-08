#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long power(int a, int b){
    if(b == 0) return 1;
    long long ans;
    ans = power(a,b/2);
    if(b & 1){ // odd
        ans = a * ans * ans;
    }else{
        ans = ans * ans;
    }
   return ans; 
}
int main() {
    int a = 100;
    int b = 1;
    cout<< power(a,b);
    return 0;
}
