#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> unionArr(vector<int> arr1, vector<int> arr2){
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0;
    vector<int> uni;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            uni.push_back(arr1[i]);
            i++;
        }else if(arr1[i] > arr2[j]){
            uni.push_back(arr2[j]);
            j++;
        }else{
            if(i < n) uni.push_back(arr1[i]);
            else {
                if(j < m) uni.push_back(arr2[j]);
            }
            i++; j++;
        }
    }
    while(i < n){
        uni.push_back(arr1[i]);
        i++;
    }
    while(j < m){
        uni.push_back(arr2[j]);
        j++;
    }
    return uni;
}


vector<int> intersect(vector<int> arr1, vector<int> arr2){
    int n = arr1.size(), m = arr2.size();
    int i = 0, j = 0;
    vector<int> inter;
    while(i < n && j < m){
        if(arr1[i] == arr2[j]){
            if(i < n) inter.push_back(arr1[i]);
            else {
                if(j < m) inter.push_back(arr2[j]);
            }
            i++; j++;
        }else if(arr1[i] > arr2[j]){
            j++;
        }else{
            i++;
        }
    }
    return inter;
}


int main() {
    // Write C++ code here
    vector<int> arr2 = {1, 3, 4, 5, 7};
    vector<int> arr1 = {1};
    vector<int> uni = unionArr(arr1,arr2);
    for(int i : uni){
        cout<< i << " ";
    }
    cout<< endl;
    
    vector<int> inter = intersect(arr1,arr2);
    for(int i : inter){
        cout<< i << " ";
    }
    cout<< endl;
    return 0;
}

// Input: arr1[] = {1, 3, 4, 5, 7}
//         arr2[] = {2, 3, 5, 6} 
// Output: Union : {1, 2, 3, 4, 5, 6, 7} 
//          Intersection : {3, 5}
