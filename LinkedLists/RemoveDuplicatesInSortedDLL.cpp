/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    Node* n = head;
    Node* p = nullptr;
    Node* curr = head;
    while(temp->next){
        curr = temp;
        temp = temp->next;
        n = curr->next;
        p = curr->prev;
        if(curr->data == n->data){
            if(n)n->prev = p;
            if(p) p->next = n;
            else head = n;
            delete curr;
        }
    }
    return head;
}
