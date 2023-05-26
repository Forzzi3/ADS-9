// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>
template <typename T>
class BST {
 private:
    struct Node {
        T value;
        size_t count;
        Node* left, * right;
    };
    Node* root;
    Node* addNode(Node* root, const T& value) {
        if (root == nullptr) {
            root = new Node;
            root->value = value;
            root->count = 1;
            root->left = root->right = nullptr;
        } else if (root->value > value) {
            root->left = addNode(root->left, value);
        } else if (root->value < value)
            root->right = addNode(root->right, value);
        else
            root->count++;
        return root;
    }
    Node* searchNode(Node* root, const T& value) {
        if (root->value == value) {
            return root;
        } else if (root->value > value) {
            return searchNode(root->left, value);
        }
        else if (root->value < value) {
            return searchNode(root->right, value);
        }
    }
    size_t heightTree(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(heightTree(root->left), heightTree(root->right)) + 1;
    }

 public:
    BST() :root(nullptr){}
    void add(const T& value) {
        root = addNode(root, value);
    }
    size_t depth() {
        return heightTree(root)-1;
    }
    size_t search(const T& value) {
        Node* tmp = searchNode(root, value);
        return tmp->count;
    }
};
#endif  // INCLUDE_BST_H_
