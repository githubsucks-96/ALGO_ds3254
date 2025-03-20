#include <iostream>
using namespace std;

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;

    // Transplant function: replaces one subtree with another
    void transplant(Node* u, Node* v) {
        if (u->parent == nullptr)       // If u is the root
            root = v;
        else if (u == u->parent->left)  // If u is a left child
            u->parent->left = v;
        else                            // If u is a right child
            u->parent->right = v;
        if (v != nullptr)               // Update v's parent
            v->parent = u->parent;
    }

    // Find the minimum node in a subtree
    Node* minNode(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    // Delete a node from BST
    void deleteNode(Node* node, int key) {
        if (node == nullptr) return;

        if (key < node->data) {
            deleteNode(node->left, key);
        } else if (key > node->data) {
            deleteNode(node->right, key);
        } else {
            // Case 1: No left child, replace with right child
            if (node->left == nullptr)
                transplant(node, node->right);

            // Case 2: No right child, replace with left child
            else if (node->right == nullptr)
                transplant(node, node->left);

            // Case 3: Node has two children
            else {
                Node* successor = minNode(node->right);
                if (successor->parent != node) {
                    transplant(successor, successor->right);
                    successor->right = node->right;
                    successor->right->parent = successor;
                }
                transplant(node, successor);
                successor->left = node->left;
                successor->left->parent = successor;
            }
            delete node;
        }
    }

    // Insert a node into BST
    void insert(Node*& root, Node* parent, int val) {
        if (root == nullptr) {
            root = new Node(val);
            root->parent = parent;
            return;
        }
        if (val < root->data)
            insert(root->left, root, val);
        else
            insert(root->right, root, val);
    }

    // Inorder traversal (sorted order)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        insert(root, nullptr, val);
    }

    void deleteKey(int key) {
        deleteNode(root, key);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Inorder before deletion: ";
    tree.printInorder(); // Output: 3 5 7 10 12 15 18

    tree.deleteKey(10);

    cout << "Inorder after deleting 10: ";
    tree.printInorder(); // Output: 3 5 7 12 15 18

    return 0;
}
