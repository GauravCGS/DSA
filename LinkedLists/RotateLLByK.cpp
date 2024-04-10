/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

int getLength(Node *head){
     Node *temp = head;
     int len = 0;
     while(temp){
          temp = temp->next;
          len++;
     }
     return len;
}

Node *reverseLL(Node *head, int k, Node* &nxt){
     Node *temp = head, *curr = head, *prev = NULL;
     int i = 0;
     while(i < k){
          temp = curr->next;
          curr->next = prev;
          prev = curr;
          curr = temp;
          i++;
     }
     nxt = curr;
     return prev;
}

void printLL(Node *head){
     Node *temp = head;
     while(temp){
          temp = temp->next;
          cout<<temp->data<<"-->";
     }
     cout<<"NULL"<<endl;
}


Node *rotate(Node *head, int k) {
     int l = getLength(head);
     if (l == 0) return head; // Handle empty list
     k %= l; // Calculate effective rotation value
     if (k == 0) return head; // No rotation needed
     int nk = l - k;
     if (nk < 0) nk += l; // Adjust nk for cases where k > l
     Node *tn = NULL;
     Node *dummy = NULL;
     Node *h1 = reverseLL(head, nk, tn);
     Node *h2 = reverseLL(tn, k, dummy);
     // printLL(h1);
     Node *temp = h1;
     while(temp->next) {
          temp = temp->next;
     }
     temp->next = h2;
     // return h2;
     Node *ret = reverseLL(h1, l, dummy);
     return ret;
     // return h1;
}
