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

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int len1 = 0, len2 = 0;
    Node *temp1 = firstHead, *temp2 = secondHead;
    Node* larger = NULL;
    Node* smaller = NULL;
    while(temp1 && temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    int diff = 0;
    if(temp1){  // first LL is longer
        while(temp1){
            temp1 = temp1->next;
            diff++;
        }
        int count = 0;
        temp1 = firstHead;
        temp2 = secondHead;
        while(count != diff){
            temp1 = temp1->next;
            count++;
        }
    }else if(temp2){    // second LL is longer
        while(temp2)
        {temp2 = temp2->next;
        diff++;}
        int count = 0;
        temp2 = secondHead;
        temp1 = firstHead;
        while(count != diff){
            temp2 = temp2->next;
            count++;
        }
    }else{      // same length
        temp1 = firstHead;
        temp2 = secondHead;
    }
    while(temp1!=temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}
