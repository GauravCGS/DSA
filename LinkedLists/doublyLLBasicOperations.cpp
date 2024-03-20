// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        
        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void insertAtHead(Node* &head, int data){
    if(head == NULL){
        cout<<"NO head node"<<endl;
        return;
    }
    Node* temp = new Node(data);
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int data){
    if(tail == NULL){
        cout<<"NO tail node"<<endl;
        return;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPos(int pos,Node* &head,Node* &tail,int data){
    Node* NN = new Node(data);
    int count = 1;
    Node* temp = head;
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    while(count < pos-1){
        count++;
        temp = temp->next;
    }
    Node* prev = temp;
    Node* curr = temp->next;
    if(curr == NULL){
        insertAtTail(tail,data);
        return;
    }
    prev->next = NN;
    curr->prev = NN;
    NN->prev = prev;
    NN->next = curr;
    return;
}

void deleteNode(int pos, Node* &head, Node* &tail){
    int count = 1;
    Node* temp = head;
    if(pos == 1){
        head = temp->next;
        head->prev = NULL;
        delete temp;
        return;
    }
    while(count < pos-1){
        count++;
        temp = temp->next;
    }
    Node* prev = temp;
    Node* curr = temp->next;
    Node* next = temp->next->next;
    prev->next = next;
    if(next!=NULL) next->prev = prev;
    else tail = prev;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
}

void print(Node* &head){
    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }
    cout<<"NULL<--";
    Node* temp = head;
    while(temp!= NULL){
        if(temp->next == NULL){
            cout<<temp->data<<"-->NULL"<<endl;
            return;
        }
        cout<<temp->data<<"==";
        temp=temp->next;
    }
}

void showHeadTail(Node* &head,Node* &tail){
    cout<<"Head = "<<head->data<<endl;
    cout<<"Tail = "<<tail->data<<endl;
    return;
}

void reverseLL(Node* &head){
    Node* temp = head;
    Node* curr = head;
    while(curr!= NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    head = temp->prev;
}

int main() {
    Node* N = new Node(90);
    Node* head = N;
    Node* tail = N;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtTail(tail,40);
    insertAtTail(tail,300);
    print(head);
    deleteNode(5,head,tail);
    print(head);
    insertAtPos(3,head,tail,50);
    print(head);
    reverseLL(head);
    print(head);
    return 0;
}
