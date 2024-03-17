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

void insertAtTail(int data, Node* &tail){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtPos(int data, Node* &head,Node* &tail, int pos){
    Node* temp = new Node(data);
    Node* I = head;
    int count = 1;
    if(pos == 1){
        insertAtHead(data,head);
        return;
    }
    while(count < pos-1){
        I = I->next;
        if(I->next == NULL){
            insertAtTail(data,tail);
            return;
        }
        count++;
    }
    Node* next = I->next;
    I->next = temp;
    temp->next = next;
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
    Node *head = n1;
    Node *tail = n1;
    insertAtHead(20,head);
    insertAtTail(30,tail);
    insertAtTail(30,tail);
    insertAtPos(50,head,tail,5);
    insertAtTail(69,tail);
    print(head);

    return 0;
}
