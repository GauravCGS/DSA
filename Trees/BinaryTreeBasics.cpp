// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    
};

void createTree(Node* &root){
    int data;
    cout<<"enter data : "<<endl;
    cin>> data;
    if(data == -1) return;
    Node* nn = new Node(data);
    root = nn;
    cout<<"Creating left node of "<<nn->data<<endl;
    createTree(nn->left);
    cout<<"Creating right node of "<<nn->data<<endl;
    createTree(nn->right);
    return;
}

void bfs(Node* &root){
    if(root == NULL) return;
    queue<Node*> qt;
    qt.push(root);
    while(!qt.empty()){
        Node *temp = qt.front();
        cout<<temp->data<<" ";
        qt.pop();
        if(temp->left)qt.push(temp->left);
        if(temp->right)qt.push(temp->right);
    }
}

void bfsR(Node* &root){
    if(root == NULL) return;
    queue<Node*> qt;
    stack<int> st;
    qt.push(root);
    while(!qt.empty()){
        Node *temp = qt.front();
        // cout<<temp->data<<" ";
        st.push(temp->data);
        qt.pop();
        if(temp->left)qt.push(temp->left);
        if(temp->right)qt.push(temp->right);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void inorderTraversal(Node* root){
    Node* temp = root;
    if(temp == NULL) return;
    inorderTraversal(temp->left);
    cout<<temp->data<<" ";
    inorderTraversal(temp->right);
    return;
}

void preorderTraversal(Node* root){
    Node* temp = root;
    if(temp == NULL) return;
    cout<<temp->data<<" ";
    preorderTraversal(temp->left);
    preorderTraversal(temp->right);
    return;
}

void postorderTraversal(Node* root){
    Node* temp = root;
    if(temp == NULL) return;
    postorderTraversal(temp->left);
    postorderTraversal(temp->right);
    cout<<temp->data<<" ";
    return;
}

int main() {
    // Write C++ code here
    // cout << "Try programiz.pro";
    Node* root = NULL;
    createTree(root);
    cout<<endl;
    // cout<<root->data;
    bfsR(root);cout<<endl;
    cout<<"inorder : ";
    inorderTraversal(root);cout<<endl;
    cout<<"preorder : ";
    preorderTraversal(root);cout<<endl;
    cout<<"postorder : ";
    postorderTraversal(root);cout<<endl;
    return 0;
}
