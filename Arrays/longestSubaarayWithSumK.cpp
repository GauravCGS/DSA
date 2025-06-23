// n square solution
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int m = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum+=arr[j];
                if(sum == k){
                    m = max(m,j-i+1);
                }
            }
            res = max(m,res);
        }
        return res;
    }
};
