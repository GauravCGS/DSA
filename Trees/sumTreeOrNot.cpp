// n square solution 

class Solution
{
    public:
    
    int findSum(Node* node){
        if(node == NULL) return 0;
        int sumL = findSum(node->left);
        int sumR = findSum(node->right);
        int sum = sumL + sumR + node->data;
        return sum;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         Node* node = root;
         if(node == NULL || (node->left == NULL && node->right == NULL)) return true;
         
         bool l = isSumTree(node->left);
         bool r = isSumTree(node->right);
         
         int sumL = findSum(node->left);
         int sumR = findSum(node->right);
         
         if((node->data == sumL + sumR) && l && r) return true;
         return false;
    }
};

// n soln

class Solution
{
    public:
    
    int findSum(Node* node, bool &f){
        if(node == NULL){
            return 0;
        }
        if(node->left == NULL && node->right == NULL){
            return node->data;
        }
        int sumL = findSum(node->left,f);
        int sumR = findSum(node->right,f);
        if(node->data != sumL + sumR) f = false;
        return node->data + sumL +sumR;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         Node* node = root;
         bool f = true;
         int sum = 0;
         findSum(node,f);
         return f;
    }
};
