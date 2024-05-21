class Solution
{
public:
    
    void solve(Node* node, int len, int &maxLen, int sum, int &maxSum){
        if(!node) return;
        if(!node->left && !node->right){
            sum+= node->data;
            len+= 1;
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen){
                if(sum > maxSum) maxSum = sum;
            }
            return;
        }
        sum+= node->data;
        len+= 1;
        solve(node->left, len, maxLen, sum, maxSum);
        solve(node->right, len, maxLen, sum, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum = 0, maxSum = INT_MIN;
        int len = 0, maxLen = INT_MIN;
        solve(root, len, maxLen, sum, maxSum);
        return maxSum;
    }
};
