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