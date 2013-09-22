#include "BinaryTree.h"

template <class K, class D>
BinaryTree<K, D>::~BinaryTree()
{
    delete root;
}

template <class K, class D>
void BinaryTree<K, D>::add(K key, D data, bool override)
{
    if (!root) {
        root = new Node(key, data);
        return;
    }

    Node *tmp = root, *parent;
    bool isLeft;
    while (tmp) {
        if (key == tmp->key) {
            if (override) {
                tmp->data = data;
            }
            return;
        }
        isLeft = key < tmp->key;
        parent = tmp;
        if (isLeft) {
            tmp = tmp->left;
        } else {
            tmp = tmp->right;
        }
    }
    if (isLeft) {
        parent->left = new Node(key, data);
    } else {
        parent->right = new Node(key, data);
    }
    return;
}

template <class K, class D>
D BinaryTree<K, D>::search(K key)
{
    if (!root) {
        throw "There is no elements in tree!";
    }
    Node *tmp = root;
    while (tmp) {
        if (key == tmp->key) {
            return tmp->data;
        } else {
            tmp = key < tmp->key ? tmp->left : tmp->right;
        }
    }
    throw "Element not found!";
}

template <class K, class D>
void BinaryTree<K, D>::remove(K key)
{
    if (!root) {
        throw "There is no elements in tree!";
    }
    Node *tmp = root, *parent;
    bool isLeft;
    while (tmp) {
        if (key == tmp->key) {
            Node *toRemove = tmp;
            if (isLeft) {
                parent->left = tmp->left;
            } else {
                parent->right = tmp->right;
            }
            toRemove = nullptr;
            return;
        } else {
            parent = tmp;
            isLeft = key < tmp->key;
            tmp = isLeft ? tmp->left : tmp->right;
        }
    }
    throw "Element not found!";
}