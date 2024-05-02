class Solution {
public:
    void leftBound(Node* node, vector<int> &left){
        if(node == NULL || (node->left == NULL && node->right == NULL)){
            return;
        }
        left.push_back(node->data);
        if(node->left)leftBound(node->left, left);
        else leftBound(node->right,left);
        return;
    }
    
    void rightBound(Node* node, vector<int> &right){
        if(node == NULL || (node->left == NULL && node->right == NULL)){
            return;
        }
        if(node->right)rightBound(node->right, right);
        else rightBound(node->left, right);
        right.push_back(node->data);
        return;
    }
    
    void bottomBound(Node* node, vector<int> &leaves){
        if(node == NULL)
           return;
       if(node->left == NULL && node->right == NULL){
           if(node)leaves.push_back(node->data);
            return;
        }
        bottomBound(node->left, leaves);
        bottomBound(node->right, leaves);
        return;
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        ans.push_back(root->data);
        leftBound(root->left, ans);
        bottomBound(root->left, ans);
        bottomBound(root->right, ans);
        rightBound(root->right, ans);
        return ans;
    }
};
