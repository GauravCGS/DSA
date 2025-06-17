class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zeroFirst = 0; //make sure this pointer is on the first zero
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                swap(nums[i],nums[zeroFirst]);
                zeroFirst++;
            }
        }
    }
};
