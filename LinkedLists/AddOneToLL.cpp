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
void *solve(Node* &n, int &carry){
    if(!n->next){
        int sum = n->data+1;
        carry = sum/10;
        n->data = sum % 10;
        return n;
    }
    solve(n->next,carry);
    int sum = n->data+carry;
    carry = sum/10;
    n->data = sum%10;
}

void addNodeAtHead(Node* &head, int num){
    Node *nn = new Node(num);
    Node *temp = head;
    nn->next = temp;
    head = nn;
}

Node *addOne(Node *head)
{
    // Write Your Code Here.
    int carry = 0;
    solve(head,carry);
    if(carry > 0)addNodeAtHead(head,carry);
    return head;
}
