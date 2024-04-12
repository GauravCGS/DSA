#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
    
    Node() {
        this->data = 0;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
    Node(int data) {
        this->data = data;
        this->prev = nullptr;
        this->next = nullptr;
    }
    
    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

vector<pair<int, int>> findPairs(Node* head, int k) {
    vector<pair<int,int>> res;
    if (head == nullptr || head->next == nullptr) // If the list is empty or has only one node
        return res;
    
    Node* l = head;
    Node* r = head;
    
    // Move 'r' to the last node
    while (r->next != nullptr)
        r = r->next;
    
    // Find pairs whose sum equals 'k'
    while (l != nullptr && r != nullptr && l != r && l->prev != r) {
        int sum = l->data + r->data;
        if (sum == k) {
            res.push_back({l->data, r->data});
            l = l->next;
            r = r->prev;
        } else if (sum < k) {
            l = l->next;
        } else {
            r = r->prev;
        }
    }
    
    return res;
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    int k = 5;
    vector<pair<int,int>> pairs = findPairs(head, k);

    cout << "Pairs whose sum equals " << k << ":" << endl;
    for (const auto& pair : pairs) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }

    // Clean up memory
    Node* temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
