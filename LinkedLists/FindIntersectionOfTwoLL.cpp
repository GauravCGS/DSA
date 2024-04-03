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
// chat GPT clean code
Node* findIntersectionGPT(Node *firstHead, Node *secondHead) {
    if (!firstHead || !secondHead) // If either list is empty, there can't be any intersection
        return NULL;

    int len1 = 1, len2 = 1; // Start counting lengths from 1 to avoid separate checks for NULL lists
    Node *temp1 = firstHead, *temp2 = secondHead;

    // Calculate lengths of both lists
    while (temp1->next) {
        temp1 = temp1->next;
        len1++;
    }

    while (temp2->next) {
        temp2 = temp2->next;
        len2++;
    }

    // If the last nodes are different, there's no intersection
    if (temp1 != temp2)
        return NULL;

    // Reset temp pointers to heads of respective lists
    temp1 = firstHead;
    temp2 = secondHead;

    // Traverse the longer list until both lists have equal remaining lengths
    if (len1 > len2) {
        int diff = len1 - len2;
        while (diff--) temp1 = temp1->next;
    } else if (len2 > len1) {
        int diff = len2 - len1;
        while (diff--) temp2 = temp2->next;
    }

    // Now both lists have equal remaining lengths
    // Traverse both lists in tandem until an intersection is found
    while (temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1; // Return intersection node
}
// using maps (extra space)
#include<bits/stdc++.h>
Node* findIntersectionMaps(Node *firstHead, Node *secondHead)
{
    //Write your code here
    unordered_map<Node*,bool> visited;
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while(temp1 != NULL){
            visited[temp1] = true;
            temp1 = temp1->next;
    }

    while(temp2 != NULL){
        if(visited.find(temp2) != visited.end()) return temp2;
        temp2 = temp2->next;
    }
    return NULL;
}
