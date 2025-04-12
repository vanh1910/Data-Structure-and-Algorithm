// Iterative C++ program to find length
// or count of nodes in a linked list

#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

// Counts number of nodes in linked list
int countNodes(Node* head) {
    Node* cur = head;
    int cnt =  0;
    while (cur != nullptr){
        ++cnt;
        cur = cur->next;
    }
    return cnt;
}

// Driver code
int main() {
      
    // Create a hard-coded linked list:
    // 1 -> 3 -> 1 -> 2 -> 1
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    // Function call to count the number of nodes
    cout << "Count of nodes is " << countNodes(head);
    return 0;
}