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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* eve = head->next;
        ListNode* two = head->next;
        while(odd->next!=NULL && eve->next!=NULL){
            odd->next = eve->next;
            odd = eve->next;
            eve->next = odd->next;
            eve = odd->next;   
        }
        odd->next = two;
        return head;
    }
};
