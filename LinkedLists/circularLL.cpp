#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/

bool isCircular(Node* head){
    // Write your code here.
    if(head == NULL) return true;
    if( head->next == NULL) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow && fast == head) return true;
        if(fast == slow) return false;
    }
    return false;
}
