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
