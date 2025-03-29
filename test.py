#include <iostream>

// BST Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value node in a BST
Node* findMin(Node* root) {
    if (root == nullptr)
        return nullptr;
    
    while (root->left != nullptr)
        root = root->left;
    
    return root;
}

// Delete a node with given value from BST
Node* deleteNode(Node* root, int value) {
    // Base case: empty tree
    if (root == nullptr)
        return root;
    
    // Navigate to the node to delete
    if (value < root->data) {
        // Value is in left subtree
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        // Value is in right subtree
        root->right = deleteNode(root->right, value);
    }
    else {
        // Found the node to delete
        
        // Case 1: Node with no children (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Node with only one child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        else {
            // Find inorder successor (smallest node in right subtree)
            Node* temp = findMin(root->right);
            
            // Copy the inorder successor's data to this node
            root->data = temp->data;
            
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }
    
    return root;
}

// Helper function to print the tree inorder
void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;
    
    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

// Example usage
int main() {
    Node* root = nullptr;
    
    // Insert some values
    root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    std::cout << "Original BST: ";
    inorderTraversal(root);
    std::cout << std::endl;
    
    // Delete a leaf node
    root = deleteNode(root, 20);
    std::cout << "After deleting 20: ";
    inorderTraversal(root);
    std::cout << std::endl;
    
    // Delete a node with one child
    root = deleteNode(root, 30);
    std::cout << "After deleting 30: ";
    inorderTraversal(root);
    std::cout << std::endl;
    
    // Delete a node with two children
    root = deleteNode(root, 50);
    std::cout << "After deleting 50: ";
    inorderTraversal(root);
    std::cout << std::endl;
    
    return 0;
}