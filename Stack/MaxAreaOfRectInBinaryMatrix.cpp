#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> NLLi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            res.push_back(-1);
            s.push(i);
        }else{
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(-1);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    return res;
}

vector<int> NLRi(vector<int> v){
    int n = v.size();
    vector<int> res;
    stack<int> s;
    for(int i = n-1; i >= 0; i--){
        if(s.empty()){
            res.push_back(n);
            s.push(i);
        }else{
            while(!s.empty() && v[i] <= v[s.top()]){
                s.pop();
            }
            if(s.empty()){
                res.push_back(n);
            }else{
                res.push_back(s.top());
            }
            s.push(i);
        }
    }
    reverse(res.begin(),res.end());
    return res;
}

int maxAreaUnderHistogram(vector<int> v){
    int n = v.size();
    vector<int> gl = NLLi(v);
    vector<int> gr = NLRi(v);
    int area = v[0];
    for(int i = 0; i < n; i++){
        int l = gr[i] - gl[i] - 1;
        area = max((l * v[i]),area);
    }
    return area;
}

int maxAreaOfRectInBinaryMat(vector<vector<int>> mat){
    int row = mat.size();
    int col = mat[0].size();
    vector<int> hist(col,0);
    int maxArea = 1;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(mat[i][j] != 0){
                hist[j]+=mat[i][j];
            }else{
                hist[j] = 0;
            }
        }
        int mah = maxAreaUnderHistogram(hist);
        maxArea = max(maxArea, mah);
    }
    return maxArea;
}


int main(){
    vector<vector<int>> mat = {{1,1,1,0},{1,1,1,1},{1,1,0,0}};
    for(int i = 0; i<mat.size();i++){
        for(int j = 0; j < mat[0].size(); j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    int area = maxAreaOfRectInBinaryMat(mat);
    cout<<"max area : "<<area;
    
    return 0;
}
