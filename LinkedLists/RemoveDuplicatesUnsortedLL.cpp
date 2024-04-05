#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head)
{
    // Write your code here
    unordered_map<int, bool > visited;
    Node* prev = nullptr;
    Node* curr = head;
    while(curr){
        if(visited[curr->data]){      // no change of prev
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }else{
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}
