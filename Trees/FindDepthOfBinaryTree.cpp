// sol 1
class Solution{
    public:
    //Function to find the height of a binary tree.
    
    int solve(struct Node* node, int h){
        if(node == NULL) return h;
        h++;
        h = max(solve(node->left,h),solve(node->right,h));
        // return h;
    }
    
    int height(struct Node* node){
        // code here 
        int h = 0;
        return solve(node,h);
    }
};


//sol 2


class Solution{
    public:
    //Function to find the height of a binary tree.
    
    int height(struct Node* node){
        // code here 
        if(node == NULL) return 0;
        //go left get height 
        int left = height(node->left);
        //go right get height
        int right = height(node->right);
        //compare left and right heights
        int h = max(left, right) + 1;
        return h;
        
    }
};
