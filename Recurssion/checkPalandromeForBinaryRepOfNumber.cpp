#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void bin(long long N, vector<int> &res){
    if( N == 1 || N == 0) {
        res.push_back(N);
        return;
    }
    int r = N%2;
    if( r == 0) res.push_back(0);
    else res.push_back(1);
    N = N/2;
    bin(N,res);
    return;
}

bool check(vector<int>&v, int l, int r){
    if(l >= r) return true;
    if(v[l] != v[r]) return false;
    else return check(v,l+1,r-1);
}
int main() {
    long long N = 243;
    vector<int> res;
    bin(N,res);
    for(int i : res){
        cout<<i;
    }
    cout<<endl;
    if(check(res,0,res.size()-1)){
        cout<<"Palandrome\n";
    }else{
        cout<<"Not a Palandrome\n";
    }
    return 0;
}
