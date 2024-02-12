#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v){
    for(int i : v){
        cout<<i<<" ";
    }
    cout<<endl;
}

vector<int> NGLi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            res.push_back(0);
            s.push(i);
        }else{
            while(!s.empty() && v[i] >= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(0);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    return res;
}

vector<int> NGRi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        if(s.empty()){
            res.push_back(n-1);
            s.push(i);
        }else{
            while(!s.empty() && v[i] >= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(n-1);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int rainWaterTrap(vector<int> v){
    int n = v.size();
    vector<int> ngli = NGLi(v);
    vector<int> ngri = NGRi(v);
    vector<int> depth(n);
    for(int i = 0; i < n; i++){
        depth[i] = min(v[ngli[i]],v[ngri[i]]) - v[i];
    }
    int volume = 0;
    for(int i = 0; i < n; i++){
        int width = ngri[i] - ngli[i] - 1;
        volume += depth[i]*width;
    }
    return volume;
}

int main() {
    // Write C++ code here
    cout << "Hello world!\n";
    vector<int> v = {5,5,5,5};
    vector<int> ngli = NGLi(v);
    vector<int> ngri = NGRi(v);
    cout<<"NGL : ";
    print(ngli);
    cout<<"NGR : ";
    print(ngri);
    int volume = rainWaterTrap(v);
    cout<<"Total unit water traped : "<<volume;
    return 0;
}
