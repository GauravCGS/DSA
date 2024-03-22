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
// unordered map is used here
#include<bits/stdc++.h>
Node *firstNode(Node *head)
{
    //    Write your code here.
    unordered_map<Node*, bool> visited;
    Node* temp = head;
    // while(temp != NULL && visited.find(temp) == visited.end()){
    while(temp != NULL && visited[temp] != true){
        visited[temp] = true;
        temp = temp->next;
    }
    return temp;
}
