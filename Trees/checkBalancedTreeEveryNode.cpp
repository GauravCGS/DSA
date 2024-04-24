//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
//sol 1
class Solution{
    private:
        int height(Node* node){
            if(node==NULL) return 0;
            int l = height(node->left);
            int r = height(node->right);
            int h = max(l,r) + 1;
            return h;
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        Node* node = root;
        if(node == NULL) return true;
            bool l = isBalanced(node->left);
            bool r = isBalanced(node->right);
        int hl = height(node->left);
        int hr = height(node->right);
        if(abs(hl-hr)<=1 and l&r) return true;
        return false;
    }
};

//SOL 2

class Solution{
    private:
        int height(Node* node, bool &res){
            if(node==NULL) {return 0; res = true;};
            int l = height(node->left,res);
            int r = height(node->right,res);
            int h = max(l,r) + 1;
            if(abs(l-r)<=1) res = res&true;
            else res = res&false;
            return h;
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        Node* node = root;
        if(node == NULL) return true;
        bool ans = true;
        int h = height(root,ans);
        return ans;
    }
};


