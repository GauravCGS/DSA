// There are two solutions first is by finding length of LL it takes two passes over the LL
// Second id using fast and slow ptr takes only one pass
/*
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
*/
/**
int getLength(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    int len = getLength(head);
    int j = len - K + 1;
    int i = 1;
    if(j == 1){
        head = head->next;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(i != j){
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    delete temp;
    return head;
}
*/

// -- Fast and slow pointer solution
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        ListNode *prev = NULL;
        int k = 1;
        while(k!=n){
            fast = fast->next;
            k++;
        }
        while(fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == head){
            head = head->next;
            delete slow;
            return head;
        }
        if(prev!=NULL)prev->next = slow->next;
        delete slow;
        return head;
    }
};
