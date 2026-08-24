// BST and AVL Implementation Template
// Instructions: Implement the missing function definitions for each class.
// Each function has comments indicating what it should do.

#include <iostream>
#include <queue>
#include  <algorithm>

// Binary Search Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;  // For AVL Tree

    Node(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value <= node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        
        return node;
    }

    Node* searchRec(Node* node, int value) {
        if (node == nullptr) return nullptr;
        if (node->data == value) return node;
        if (node->data > value) return searchRec(node->left, value);
        else return searchRec(node->right, value);
    }

    Node* findMin(Node* node) {
        if (node == nullptr) return nullptr;
        if (node->left == nullptr) return node;
        return findMin(node->left);
    }

    Node* deleteRec(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        else if (node->data > value) {
            node->left = deleteRec(node->left, value);
        }
        else if (node->data < value) {
            node->right = deleteRec(node->right, value);
        }
        else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteRec(node->right, temp->data);
            }
        }
        return node;
    }

    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        std::cout << node->data << " ";
        inorderRec(node->right);
    }

    void clearRec(Node* node) {
        if (node == nullptr) return;
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }
    
public:
    BST() : root(nullptr) {}

    ~BST() {
        clearRec(root);
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    bool search(int value) {
        return (searchRec(root, value) != nullptr);
    }

    void remove(int value) {
        root = deleteRec(root, value);
    }

    void inorder() {
        inorderRec(root);
        std::cout << "\n";
    }
};

// AVL Tree Implementation
class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) return 0;
        // TODO: Implement height calculation
        return node->height;
    }

    int getBalance(Node* node) {
        // TODO: Implement balance factor calculation
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        // TODO: Implement right rotation
        //rotation
        Node* temp = y;
        y = y->left;
        temp->left = y->right;
        y->right = temp;
        //update height
        y->right->height = 1 + std::max(height(y->right->left), 
                    height(y->right->right)); 
        y->height = 1 + std::max(height(y->left), 
                            height(y->right)); 
        return y;
    }

    Node* leftRotate(Node* x) {
        //rotation
        Node* temp = x;
        x = x->right;
        temp->right = x->left;
        x->left = temp;
        //update height
        x->left->height = 1 + std::max(height(x->left->left), 
                    height(x->left->right)); 
        x->height = 1 + std::max(height(x->left), 
                            height(x->right)); 
        // TODO: Implement left rotation
        return x;
    }

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        node->height += 1;
        if (value <= node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }
        
        return node;
    }

    void inorderRec(Node* node) {
        if (node == nullptr) return;
        inorderRec(node->left);
        std::cout << node->data << " ";
        inorderRec(node->right);
    }

    void clearRec(Node* node) {
        if (node == nullptr) return;
        clearRec(node->left);
        clearRec(node->right);
        delete node;
    }
    void printBFS(Node* node){
        std::queue<Node*> qu;
        qu.push(root);
        int temp = root->height;
    
        while(!qu.empty()){
            Node* current = qu.front();
            qu.pop();
            if (current == nullptr) continue;
            if (height(current)!= temp){
                std::cout << "\n";
                temp = height(current);
            }
            
            std::cout << current -> data << " ";

            qu.push(current->left);
            qu.push(current->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree() {
        // TODO: Implement destructor
        clearRec(root);
    }

    void insert(int value) {
        root = insertRec(root, value);
        //std::  cout << "debug" << value << " " << getBalance(root)<< std::endl;
        if (getBalance(root) > 0 && getBalance(root->left) > 0){
            root = rightRotate(root);
            //left left case
        }else if (getBalance(root) > 0 && getBalance(root->left) < 0){
            root-> left = leftRotate(root->left);
            root = rightRotate(root);
            //left right case
        }else if (getBalance(root) < 0 && getBalance(root->right) < 0){
            root = leftRotate(root);
            //right right case;
        }else if (getBalance(root) < 0 && getBalance(root->right) > 0){
            root->right = rightRotate (root->right);
            root = leftRotate(root);
        }
        //std::  cout << "debug" << value << " " << getBalance(root)<< std::endl;

    }

    void inorder() {
        inorderRec(root);
        std::cout << "\n";
    }

    void printTree(){
        printBFS(root);
    }

    bool isBalanced() {
        // TODO: Implement balance check
        return !getBalance(root);
    }
};

// Testing function - DO NOT MODIFY
void testTrees() {
    std::cout << "Testing Binary Search Tree:\n";
    BST bst;
    
    //Insert elements
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    
    std::cout << "Inorder traversal: ";
    bst.inorder();
    
    std::cout << "Search 30: " << (bst.search(30) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;
    
    bst.remove(20);
    std::cout << "After removing 30, inorder traversal: ";
    bst.inorder();

    std::cout << "\nTesting AVL Tree:\n";
    AVLTree avl;
    
    // // Insert elements that would cause rotations
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    std::cout << "Inorder traversal: ";
    avl.inorder();
    //avl.printTree();
    
    std::cout << "Is tree balanced? " << (avl.isBalanced() ? "Yes" : "No") << std::endl;
}

int main() {
    testTrees();
    return 0;
}