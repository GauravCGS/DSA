/**
 * Definition of doubly linked list:
 *
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

Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node *temp = head;
    Node *curr = head;
    Node *prev = NULL;
    
    while(temp){
        if(temp->data == k){
            curr = temp;
            temp = temp->next;
            if(temp)temp->prev = prev;
            //check if prev exists when removing head node prev will always be NULL
            if(prev){
                prev->next = temp;
            }else{
                head = temp;        // when prev is null update head
            } 
            delete curr;
        }else{
             prev = temp;
             temp = temp->next;
        }   
    }
    if(!prev) return NULL;      // check if prev exists if not that means all the nodes has been deleted so return NULL
    return head;
}
