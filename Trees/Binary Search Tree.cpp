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
    Node* temp = root;
    queue<Node*> qt;
    qt.push(temp);
    while(!qt.empty()){
        temp = qt.front();
        cout<<temp->data<<" ";
        qt.pop();
        if(temp->left)qt.push(temp->left);
        if(temp->right)qt.push(temp->right);
    }
}

int main() {
    // Write C++ code here
    // cout << "Try programiz.pro";
    Node* root = NULL;
    createTree(root);
    cout<<endl;
    cout<<root->data;
    bfs(root);
    return 0;
}
