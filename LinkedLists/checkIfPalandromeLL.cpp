/****************************************************************

    Following is the class structure of the Node class:

    class Node
    {
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
    };

*****************************************************************/
#include<bits/stdc++.h>

void reverseLL(Node* &head){
    Node* curr = head;
    Node* temp = head;
    Node* prev = NULL;
    while(curr!=NULL){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

bool compare(Node* A, Node* B){
    while(A!=NULL && B!=NULL){
        if(A->data != B->data) return false;
        A=A->next;
        B=B->next;
    }
    return true;
}

bool isPalindrome(Node *head)
{
    // write your code here
    Node* temp = head;
    Node* mid = findMid(head);
    reverseLL(mid->next);
    return compare(temp,mid->next);
}
// This function does not take any extra space
bool isPalindromeWithoutExtraSpace(Node *head)
{
    // write your code here
    Node* temp = head;
    Node* mid = findMid(head);
    reverseLL(mid->next);
    return compare(temp,mid->next);
}
//This function uses extra space, A stack
bool isPalindrome(Node *head)
{
    // write your code here
    Node* temp = head;
    stack<int> s;
    if(temp->next == NULL) return true;
    while(temp!=NULL){
        s.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        if(temp->data == s.top()) s.pop();
        temp = temp->next;
    }
    if(s.empty()) return true;
    return false;
}
