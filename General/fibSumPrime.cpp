// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    if(n < 2) return true;
    for(int i = 2; i<=sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

long long fibSum(int n){
    vector<int> v(n);
    v[0] = 0;
    v[1] = 1;
    long long sum = 1;
    for(int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
        if(isPrime(i)){
            sum+=v[i];
        }
    }
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
    return sum;
}

int main() {
    // Write C++ code here
    cout << "Try programiz.pro \n";
    if(isPrime(1997)) cout<<"Prime \n";
    else cout<<"Not Prime \n";
    cout<<fibSum(10);

    return 0;
}
