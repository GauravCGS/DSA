/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        if(!node) return NULL;
        if(node == p || node == q){
            return node;
        }
        TreeNode* left = lowestCommonAncestor(node->left,p,q);
        TreeNode* right = lowestCommonAncestor(node->right,p,q);
        if(!left) return right;
        else if(!right) return left;
        return node;
    }
};
