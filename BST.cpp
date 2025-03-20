#include <iostream>
using namespace std;

template <class T>
class BinaryTree {
private:
    class Node {  // Internal Node class
    public:
        T data;
        Node* left;
        Node* right;
        Node* parent; // Pointer to the parent node

        Node(const T& value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root; // Root of the tree

    // Helper function for in-order traversal
    void inOrderHelper(Node* node) {
        if (!node) return;
        inOrderHelper(node->left);
        cout << node->data << " ";
        inOrderHelper(node->right);
    }

    // Helper function for searching a node
    Node* searchHelper(Node* node, const T& key) {
        if (!node || node->data == key)
            return node;

        if (key < node->data)
            return searchHelper(node->left, key);
        else
            return searchHelper(node->right, key);
    }

    // Helper function for inserting a node
    Node* insertHelper(Node* node, Node* parent, const T& key) {
        if (!node) {
            Node* newNode = new Node(key);
            newNode->parent = parent;
            return newNode;
        }

        if (key < node->data)
            node->left = insertHelper(node->left, node, key);
        else if (key > node->data)
            node->right = insertHelper(node->right, node, key);

        return node;
    }

    // Helper function for finding the minimum value node in a subtree
    Node* minValueNode(Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    // Helper function for deleting a node
    Node* deleteHelper(Node* node, const T& key) {
        if (!node) return node;

        if (key < node->data)
            node->left = deleteHelper(node->left, key);
        else if (key > node->data)
            node->right = deleteHelper(node->right, key);
        else {
            // Case 1: No child
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            }
            // Case 2: One child
            else if (!node->left) {
                Node* temp = node->right;
                temp->parent = node->parent;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                temp->parent = node->parent;
                delete node;
                return temp;
            }
            // Case 3: Two children
            else {
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteHelper(node->right, temp->data);
            }
        }
        return node;
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert a value into BST
    void insert(const T& key) {
        root = insertHelper(root, nullptr, key);
    }

    // Search for a value
    bool search(const T& key) {
        return searchHelper(root, key) != nullptr;
    }

    // Delete a value from BST
    void remove(const T& key) {
        root = deleteHelper(root, key);
    }

    // In-order Traversal
    void inOrder() {
        inOrderHelper(root);
        cout << endl;
    }
};

// Test the BST
int main() {
    BinaryTree<int> bst;
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    cout << "In-order Traversal: ";
    bst.inOrder(); // Expected Output: 3 5 7 10 12 15 18

    cout << "Search 7: " << (bst.search(7) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;

    cout << "Deleting 5...\n";
    bst.remove(5);
    cout << "In-order Traversal after deletion: ";
    bst.inOrder(); // Expected Output: 3 7 10 12 15 18

    return 0;
}

