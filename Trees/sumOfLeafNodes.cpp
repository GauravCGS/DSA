//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 

void solve(Node* node, int &sum){
    if(node->left == NULL && node->right == NULL){
        sum+=node->data;
        return;
    }
    if(node->left)solve(node->left,sum);
    if(node->right)solve(node->right,sum);
    return;
}

int sumLeaf(Node* root)
{
    // Code here
    int sum = 0;
    solve(root,sum);
    return sum;
}
