#include <iostream>
using namespace std;

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to find index of a value in an array
    int search(int arr[], int start, int end, int value) {
        for (int i = start; i <= end; i++) {
            if (arr[i] == value) return i;
        }
        return -1; // Should never reach here if input is valid
    }

    // Helper function to build the tree
    Node* buildTreeHelper(int inorder[], int preorder[], int& preIndex, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        // Pick the current root node from preorder
        int rootValue = preorder[preIndex++];
        Node* node = new Node(rootValue);

        if (inStart == inEnd) return node; // Leaf node

        // Find root position in inorder traversal
        int inIndex = search(inorder, inStart, inEnd, rootValue);

        // Recursively build left and right subtrees
        node->left = buildTreeHelper(inorder, preorder, preIndex, inStart, inIndex - 1);
        node->right = buildTreeHelper(inorder, preorder, preIndex, inIndex + 1, inEnd);

        return node;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to build tree from inorder and preorder traversals
    void buildTree(int inorder[], int preorder[], int n) {
        int preIndex = 0;
        root = buildTreeHelper(inorder, preorder, preIndex, 0, n - 1);
    }

    // Wrapper functions for traversals
    void printInorder() {
        inorder(root);
        cout << endl;
    }

    void printPreorder() {
        preorder(root);
        cout << endl;
    }

    void printPostorder() {
        postorder(root);
        cout << endl;
    }
};

// Driver Code
int main() {
    BinaryTree tree;
    int inorder[] = {3, 5, 6, 7, 10, 15, 18, 20, 25};
    int preorder[] = {10, 5, 3, 7, 6, 20, 15, 18, 25};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    tree.buildTree(inorder, preorder, n);

    cout << "Inorder Traversal: ";
    tree.printInorder();

    cout << "Preorder Traversal: ";
    tree.printPreorder();

    cout << "Postorder Traversal: ";
    tree.printPostorder();

    return 0;
}
