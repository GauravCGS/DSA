/**
 * Definition of linked list:
 *
 * class Node {
 * public:
 *      int data;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next) {
 *          this->data = data;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

 void reverseLL(Node* &head){
     Node* temp = head,*curr = head,*prev = NULL;
     while(curr){
         temp = curr->next;
         curr->next = prev;
         prev = curr;
         curr = temp;
     }
     head = prev;
 }

 void addAtHead(Node* &head,int val){
     Node *nn = new Node(val);
     nn->next = head;
     head = nn;
 }

Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    // reverseLL(num1);
    // reverseLL(num2);
    Node *head = NULL; 
    Node *temp1 = num1, *temp2 = num2;
    int carry = 0;
    int digit = 0;
    while(temp1 && temp2){
        int sum = temp1->data + temp2->data+carry;
        digit = sum%10;
        carry = sum/10;
        addAtHead(head,digit);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    Node* tempx = NULL;
    if(temp1) tempx = temp1;
    else if (temp2) tempx = temp2;
    while(tempx){
        int sum = tempx->data + carry;
        digit = sum%10;
        carry = sum/10;
        addAtHead(head,digit);
        tempx = tempx->next;
    }
    if(carry > 0){
        addAtHead(head,carry);
    }
    reverseLL(head);
    return head;
}
