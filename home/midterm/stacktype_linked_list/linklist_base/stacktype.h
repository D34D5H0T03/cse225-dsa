#ifndef STACKTYPE_H_INCLUDED
#define STACKTYPE_H_INCLUDED

class FullStack {};
class EmptyStack {};

template <class ItemType>
class StackType{
    struct NodeType{
        ItemType info;
        NodeType* next;
    };
    private:
        NodeType* topPtr;
    public:
        StackType();
        ~StackType();
        void push(ItemType item);
        void pop();
        ItemType top();
        bool isEmpty();
        bool isFull();
};


#include "stacktype.cpp"
#endif