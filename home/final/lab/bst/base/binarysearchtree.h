#ifndef BINARYSEARCHTREE_H_INCLUDED
#define BINARYSEARCHTREE_H_INCLUDED

template <class element>
struct TreeNode{
    element info;
    treeNode<element>* left;
    treeNode<element>* right;
};

enum Order{
    IN_ORDER,
    PRE_ORDER,
    POST_ORDER
};

template <class element>
class BinaryTree{
    public:
        BinaryTree();
        ~BinaryTree();
        void makeEmpty();
        bool isFull();
        bool isEmpty(); 
        int lengthIs();
        void retrieveItem(element& item, bool& found);
        void insertItem(element item);
        void deleteItem(element item);
        void resetTree(Order order);
        void getNextItem(element& item, Order order, bool& found);
        void print();
    
    private:
        TreeNode<element>* root;
        std::queue<element> inQueue;
        std::queue<element> postQueue;
        std::queue<element> preQueue;
};

#include "binarysearchtree.cpp"
#endif