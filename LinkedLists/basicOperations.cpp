// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void insertAtHead(int data, Node* &head){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(int data, Node* &head){
    Node* temp = new Node(data);
    Node* I = head;
    while(I->next != NULL){
        I = I->next;
    }
    I->next = temp;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}

int main() {
    Node *n1 = new Node(10);
    insertAtHead(20,n1);
    insertAtTail(30,n1);
    print(n1);

    return 0;
}
