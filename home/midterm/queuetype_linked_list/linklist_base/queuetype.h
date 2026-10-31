#ifndef QUEUETYPE_H_INCLUDED
#define QUEUETYPE_H_INCLUDED

class FullQueue {};
class EmptyQueue {};

template <class ItemType>
class QueueType{

    struct NodeType{
        ItemType info;
        NodeType* next;
    };

    private:
        NodeType* front;
        NodeType* rear;

    public:
        QueueType();
        ~QueueType();
        void makeEmpty();
        bool isFull();
        bool isEmpty();
        void enqueue(ItemType item);
        void dequeue(ItemType& item);
};

#include "queuetype.cpp"

#endif