#include "binarysearchtree.h"
#include <iostream>
#include <queue>

template <class element>
BinaryTree<element>::BinaryTree(){
    this->root = nullptr;
}

template <class element>
BinaryTree<element>::~BinaryTree() {
    makeEmpty();
}

template <class element>
void destroy(TreeNode<element>*& tree) {
    if (tree != nullptr) {
        destroy(tree->left);
        destroy(tree->right);
        delete tree;
        tree = nullptr; 
    }
}

template <class element>
void BinaryTree<element>::makeEmpty() {
    destroy(root);
}

template <class element>
bool BinaryTree<element>::isEmpty(){
    return (this->root == nullptr);
}

template <class element>
bool BinaryTree<element>::isFull(){
    TreeNode<element>* location;
    try{
        location = new TreeNode<element>;
        delete location;
        return false;
    }catch(std::bad_alloc exception){
        return true;
    }
}

template <class element>
void insert(TreeNode<element>*& tree, element& item){
    if(tree == nullptr){
        tree = new TreeNode<element>;
        tree->left = nullptr;
        tree->right = nullptr;
        tree->info = item;
    }   

    else if(item < tree->info){
        insert(tree->left, item);
    }
    else{
        insert(tree->right, item);
    }
}

template <class element>
void BinaryTree<element>::insertItem(element item){
    insert(root, item);
}

template <class element>
int countNodes(TreeNode<element>* tree){
    if(tree == nullptr){
        return 0;
    }
    return countNodes(tree->left) + countNodes(tree->right) + 1;
}

template <class element>
int BinaryTree<element>::lengthIs(){
    return countNodes(root);
}

template<class element>
void retrieve(TreeNode<element>* tree, element& item, bool& found){
    if(tree == nullptr){
        found = false;
    }
    else if(item < tree->info){
        retrieve(tree->left, item, found);
    }
    else if(item > tree->info){
        retrieve(tree->right, item, found);
    }
    else{
        item = tree->info;
        found = true;
    }
}

template <class element>
void BinaryTree<element>::retrieveItem(element& item, bool& found){
    retrieve(root, item, found);
}

template <class element>
void printInOrder(TreeNode<element>* tree){
    if(tree != nullptr){
        printInOrder(tree->left);
        std::cout << tree->info << " ";
        printInOrder(tree->right);
    }
}

template <class element>
void BinaryTree<element>::print(){
    printInOrder(this->root);
}

template <class element>
void getPredecessor(TreeNode<element>* tree, element& info){
    while(tree->right != nullptr){
        tree = tree->right;
    }
    info = tree->info;
}

template <class element>
void deleteNode(TreeNode<element>*& tree){
    TreeNode<element>* tempPtr;
    tempPtr = tree;
    element data;

    if(tree->left == nullptr && tree->right == nullptr){
        tree = nullptr;
        delete tempPtr;
    }
    else if(tree->left == nullptr){
        tree = tree->right;
        delete tempPtr;
    }
    else if(tree->right == nullptr){
        tree = tree->left;
        delete tempPtr;
    }
    else{
        getPredecessor(tree->left, data);
        tree->info = data;
        findDelete(tree->left, data);
    }
}

template <class element>
void findDelete(TreeNode<element>*& tree, element item){
    if(item < tree->info){
        findDelete(tree->left, item);
    }
    else if(item > tree->info){
        findDelete(tree->right, item);
    }
    else{
        deleteNode(tree);
    }
}

template <class element>
void BinaryTree<element>::deleteItem(element item){
    findDelete(root, item);
}

template <class element>
void inOrder(TreeNode<element>* tree, std::queue<element>& inQueue){
    if(tree != nullptr){
        inOrder(tree->left, inQueue);
        inQueue.push(tree->info);
        inOrder(tree->right, inQueue);
    }
}

template <class element>
void postOrder(TreeNode<element>* tree, std::queue<element>& postQueue){
    if(tree != nullptr){
        postOrder(tree->left, postQueue);
        postOrder(tree->right, postQueue);
        postQueue.push(tree->info);
    }
}

template <class element>
void preOrder(TreeNode<element>* tree, std::queue<element>& preQueue){
    if(tree != nullptr){
        preQueue.push(tree->info);
        preOrder(tree->left, preQueue);
        preOrder(tree->right, preQueue);
    }
}

template <class element>
void BinaryTree<element>::resetTree(Order order){
    switch (order)
    {
        case IN_ORDER:
            inQueue = std::queue<element>();
            inOrder(root, inQueue);
            break;
        case POST_ORDER:
            postQueue = std::queue<element>();
            postOrder(root, postQueue);
            break;
        case PRE_ORDER:
            preQueue = std::queue<element>();
            preOrder(root, preQueue);
            break;
    }
}

template <class element>
void BinaryTree<element>::getNextItem(element& item, Order order, bool& finished){
    finished = false;

    switch (order) {
        case PRE_ORDER:
            item = preQueue.front();
            preQueue.pop();          
            if (preQueue.empty()) {  
                finished = true;
            }
            break;

        case IN_ORDER:
            item = inQueue.front();
            inQueue.pop();
            if (inQueue.empty()) {
                finished = true;
            }
            break;

        case POST_ORDER:
            item = postQueue.front();
            postQueue.pop();
            if (postQueue.empty()) {
                finished = true;
            }
            break;
    }
}