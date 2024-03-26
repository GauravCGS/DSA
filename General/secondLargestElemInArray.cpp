#include <bits/stdc++.h> 
int findSecondLargest(int n, vector<int> &arr)
{
    // Write your code here.
    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for(int i = 0;i<arr.size();i++){
      if (arr[i] > max1){
        max2 = max1;
        max1 = arr[i];
      }else if((arr[i]<max1 && arr[i]>max2)){
        max2 = arr[i];
      }
    }
    if(max2 == INT_MIN) return -1;
    return max2;
}
