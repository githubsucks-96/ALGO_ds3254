#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

class MaxHeap {
private:
    vector<int> heap; // Heap stored as an array

    // Helper function to maintain heap property
    void maxHeapify(int i) {
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2; // Right child index
        int largest = i;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;
        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

public:
    // Constructor
    MaxHeap() {}

    // Get current heap size
    int size() {
        return heap.size();
    }

    // Build max-heap from an array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        int n = heap.size();
        for (int i = (n / 2) - 1; i >= 0; i--) {
            maxHeapify(i);
        }
    }

    // Insert a new key into the heap
    void insert(int key) {
        heap.push_back(key);
        int i = heap.size() - 1;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Get the maximum element (root of the heap)
    int getMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return INT_MIN;
        }
        return heap[0];
    }

    // Remove and return the maximum element
    int removeMax() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return INT_MIN;
        }
        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);
        return maxVal;
    }

    // Increase the value of a key at index i
    void increaseKey(int i, int newValue) {
        if (i >= heap.size() || heap[i] > newValue) {
            cout << "Invalid increase operation\n";
            return;
        }
        heap[i] = newValue;
        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Print the heap
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

// Test the max-heap implementation
int main() {
    MaxHeap h;

    // Insert elements
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(30);
    h.insert(40);

    cout << "Heap elements: ";
    h.printHeap();  // Expected output: 40 30 15 10 20 (may vary due to heap properties)

    cout << "Max element: " << h.getMax() << endl;

    cout << "Removing max: " << h.removeMax() << endl;
    cout << "Heap after removing max: ";
    h.printHeap();

    // Build heap from array
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    h.buildHeap(arr);
    cout << "Heap after buildHeap: ";
    h.printHeap();

    // Increase key value
    h.increaseKey(3, 22);
    cout << "Heap after increasing key at index 3 to 22: ";
    h.printHeap();

    return 0;
}

int removeMax() {
    if (heap.empty()) {
        cout << "Heap is empty!\n";
        return INT_MIN;
    }
    
    int maxVal = heap[0]; // Store max element
    heap[0] = heap.back(); // Replace root with last element
    heap.pop_back(); // Remove last element

    if (!heap.empty()) { // Only heapify if heap is not empty
        maxHeapify(0);
    }

    return maxVal;
}

#pragma once

#include <iostream>
#include <string>

#define uint unsigned int

template <class T>
class Node
{
public:
    T data;
    Node *left;
    Node *right;
};

template <class T>
class BinaryTree
{
private:
    Node<T> *root;

public:
    BinaryTree(T *preorder_nodes, T *inorder_nodes, int n)
    {
        root = build(preorder_nodes, inorder_nodes, n);
    }

    Node<T> *build(T *preorder_nodes, T *inorder_nodes, int n)
    {
        if (n == 0)
            return nullptr;

        Node<T> *node = new Node<T>;
        node->data = preorder_nodes[0];

        int i = 0;
        while (inorder_nodes[i] != preorder_nodes[0])
            i++;

        node->left = build(preorder_nodes + 1, inorder_nodes, i);
        node->right = build(preorder_nodes + i + 1, inorder_nodes + i + 1, n - i - 1);

        return node;
    }

    // Root Left Right
    void preorder(Node<T> *node = root)
    {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";

        preorder(node->left);
        preorder(node->right);
    }

    // Left Root Right
    void inorder(Node<T> *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);

        std::cout << node->data << " ";

        inorder(node->right);
    }

    // Left Right Root
    void postorder(Node<T> *node)
    {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);

        std::cout << node->data << " ";
    }
};

class BinaryTreeArray
{
private:
    int *tree;
    uint size;

public:
    uint left(uint i) {
        return 2 * i + 1;
    }

    uint right(uint i) {
        return 2 * i + 2;
    }

    uint parent(uint i) {
        return (i - 1) / 2;
    }
};
