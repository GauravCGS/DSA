#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node* next;
    
    Node(int data){
      this->data = data; 
      this->next = NULL;
    }
};

void addAtHead(int data,Node* &head){
    Node *nn = new Node(data);
    nn->next = head;
    head = nn;
}

void addAtTail(int data, Node* &head){
    Node *nn = new Node(data);
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = nn;
}


void printLL(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"null";
    cout<<endl;
}

void reverseLL(Node* &head){
    Node *curr = head;
    Node *next = head;
    Node *prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main() {
    Node *n1 = new Node(20);
    Node *head = n1;
    // cout<<n1->data;
    addAtHead(10,head);
    printLL(head);
    addAtTail(30,head);
    printLL(head);
    addAtTail(40,head);
    printLL(head);
    reverseLL(head);
    printLL(head);
    return 0;
}
